"""Version-neutral reader of MWCC's PCode and register-coloring state from a live mwcceppc.exe
(GDB Python, attached to the qemu-i386 stub). A rebuild of the recovery project's reader of the
same name (rayanht/mwcc's tools are not public): it supplies the walking and the JSON schemas,
a version module supplies the addresses and the record layouts (mwcc132_snapshot.Reader132).

Layouts follow the recovered backend (rayanht/mwcc include/compiler/PCode.h, Coloring.h):
  PCodeBlock        next +0, instructions at BLOCK_INSTRUCTIONS
  PCodeInstruction  next +0, operands at the version's offset
  InterferenceNode  next +0 (the simplify stack link), object +4, spill cost +8, ...
  gInterferenceGraph  pointer to an array of node pointers indexed by virtual register;
                      nodes 0..31 are the precolored physical registers.
The module imports without gdb so the offline tools can share SnapshotError and the schemas.
"""
import struct

SUPPORTED_TARGETS = {}
PCODE_BLOCKS_ADDRESS = None
INTERFERENCE_GRAPH_ADDRESS = None
COALESCED_REGISTERS_ADDRESS = None
PCODE_OPCODE_DESCRIPTORS_ADDRESS = None
PCODE_MAX_OPCODE = 0
VIRTUAL_REGISTER_COUNT_ADDRESSES = {}
INITIAL_OBJECT_REGISTER_LAST_ADDRESSES = {}
COALESCE_RANGE_ADDRESSES = {}
BLOCK_INSTRUCTIONS = 0x14
BLOCK_INDEX = 0x1C
MAX_BLOCKS = 20000
MAX_INSTRUCTIONS = 200000
REGISTER_CLASSES = {0: "gpr", 1: "fpr", 9: "vr"}


class SnapshotError(Exception):
    pass


def decode_operand_format(fmt):
    """Split an opcode descriptor's operand format into its operand tokens.
    A trailing '*' (or an empty token list with a variable count) marks a dynamic count."""
    tokens = [t for t in fmt.split(",") if t] if fmt else []
    return {"dynamic_operand_count": any("*" in t for t in tokens),
            "operands": [{"token": t.strip()} for t in tokens]}


class SnapshotReader:
    def __init__(self, read_memory, compiler, target_sha256):
        self._read = lambda address, size: read_memory(address, size) if size else b""
        self.compiler = compiler
        self.target = target_sha256
        self._opcode_descriptors = {}

    # primitive reads
    def u8(self, address):
        return self._read(address, 1)[0]

    def u16(self, address):
        return struct.unpack("<H", self._read(address, 2))[0]

    def s16(self, address):
        return struct.unpack("<h", self._read(address, 2))[0]

    def u32(self, address):
        return struct.unpack("<I", self._read(address, 4))[0]

    def s32(self, address):
        return struct.unpack("<i", self._read(address, 4))[0]

    def c_string(self, address, limit=256):
        out = bytearray()
        while len(out) < limit:
            chunk = self._read(address + len(out), 16)
            end = chunk.find(b"\0")
            if end >= 0:
                out += chunk[:end]
                break
            out += chunk
        return out.decode("latin-1")

    # version hooks (overridden per compiler)
    def opcode_descriptor(self, opcode):
        raise NotImplementedError

    def instruction(self, address):
        raise NotImplementedError

    def interference_node(self, address):
        raise NotImplementedError

    def reaching_definitions(self, blocks):
        return None

    # walks
    def blocks(self):
        out = []
        block = self.u32(PCODE_BLOCKS_ADDRESS)
        while block and len(out) < MAX_BLOCKS:
            instructions = []
            ins = self.u32(block + BLOCK_INSTRUCTIONS)
            while ins and len(instructions) < MAX_INSTRUCTIONS:
                rec = self.instruction(ins)
                instructions.append(rec)
                ins = rec["next"]
            out.append({"address": f"0x{block:08x}", "index": self.s32(block + BLOCK_INDEX),
                        "instructions": instructions})
            block = self.u32(block)
        if block:
            raise SnapshotError("block list did not terminate")
        return out

    def virtual_register_counts(self):
        return {name: self.s32(addr) for name, addr in VIRTUAL_REGISTER_COUNT_ADDRESSES.items()}

    def coalesce_ranges(self):
        return {REGISTER_CLASSES.get(c, str(c)): [self.s16(a), self.s16(b)] for c, (a, b) in COALESCE_RANGE_ADDRESSES.items()}

    def nodes(self, count):
        graph = self.u32(INTERFERENCE_GRAPH_ADDRESS)
        out, by_address = [], {}
        for vreg in range(count):
            p = self.u32(graph + 4 * vreg)
            if not p:
                continue
            node = self.interference_node(p)
            out.append(node)
            by_address[p] = node
        return out, by_address

    def snapshot(self, reg_class, program_counter=0):
        blocks = self.blocks()
        return {"format": "mwcc-allocator-snapshot-v1", "compiler": self.compiler, "target": self.target,
                "program_counter": f"0x{program_counter:08x}", "register_class": reg_class,
                "virtual_register_counts": self.virtual_register_counts(),
                "coalesce_ranges": self.coalesce_ranges(),
                "reaching_definitions": self.reaching_definitions(blocks), "blocks": blocks}

    def coloring_snapshot(self, reg_class, simplify_stack, program_counter=0):
        """Every interference node of the class being colored plus the simplify stack, in
        coloring order (the head of the list SimplifyGraph returned is colored first)."""
        name = REGISTER_CLASSES.get(reg_class, str(reg_class))
        count = self.virtual_register_counts().get(name, 0)
        nodes, by_address = self.nodes(count)
        order, p = [], simplify_stack
        while p and len(order) <= count:
            node = by_address.get(p) or self.interference_node(p)
            order.append(node["virtual_register"])
            p = int(node["next"])
        return {"format": "mwcc-coloring-snapshot-v1", "compiler": self.compiler,
                "program_counter": f"0x{program_counter:08x}", "register_class": name,
                "virtual_register_count": count, "coalesce_ranges": self.coalesce_ranges(),
                "simplify_order": order, "nodes": nodes}
