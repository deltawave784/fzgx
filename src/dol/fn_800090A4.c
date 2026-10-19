
#pragma simple_prepdump on
#pragma cats off
#pragma warn_notinlined off

typedef signed long s32;

typedef unsigned char u8;

typedef unsigned long u32;

typedef struct HeapBlock {
struct HeapBlock *prev;
struct HeapBlock *next;
u32 size;
} HeapBlock;
typedef struct Heap {
s32 size;
HeapBlock *used;
HeapBlock *free;
} Heap;

static u32 fzgx_pool_data_lbl_801221C0[9] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x48656170, 0x41727261, 0x7920696E,
    0x20256400
};
static u32 fzgx_pool_data_lbl_801221C0_24[14] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x30203C3D, 0x20686561, 0x70202626,
    0x20686561, 0x70203C20, 0x4E756D48, 0x65617073, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_5C[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x30203C3D, 0x2068642D, 0x3E73697A,
    0x6520696E, 0x20256400
};
static u32 fzgx_pool_data_lbl_801221C0_84[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x68642D3E, 0x616C6C6F, 0x63617465,
    0x64203D3D, 0x204E554C, 0x4C207C7C, 0x2068642D, 0x3E616C6C, 0x6F636174, 0x65642D3E, 0x70726576,
    0x203D3D20, 0x4E554C4C, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_D4[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x496E5261, 0x6E676528, 0x63656C6C,
    0x2C204172, 0x656E6153, 0x74617274, 0x2C204172, 0x656E6145, 0x6E642920, 0x696E2025, 0x64000000
};
static u32 fzgx_pool_data_lbl_801221C0_114[14] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x4F464653, 0x45542863, 0x656C6C2C,
    0x20414C49, 0x474E4D45, 0x4E542920, 0x3D3D2030, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_14C[19] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x63656C6C, 0x2D3E6E65, 0x7874203D,
    0x3D204E55, 0x4C4C207C, 0x7C206365, 0x6C6C2D3E, 0x6E657874, 0x2D3E7072, 0x6576203D, 0x3D206365,
    0x6C6C2069, 0x6E202564, 0x0
};
static u32 fzgx_pool_data_lbl_801221C0_198[13] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x4D494E4F, 0x424A5349, 0x5A45203C,
    0x3D206365, 0x6C6C2D3E, 0x73697A65, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_1CC[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x4F464653, 0x45542863, 0x656C6C2D,
    0x3E73697A, 0x652C2041, 0x4C49474E, 0x4D454E54, 0x29203D3D, 0x20302069, 0x6E202564, 0x0
};
static u32 fzgx_pool_data_lbl_801221C0_20C[15] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x30203C20, 0x61746F74, 0x616C2026,
    0x26206174, 0x6F74616C, 0x203C3D20, 0x68642D3E, 0x73697A65, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_248[18] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x68642D3E, 0x66726565, 0x203D3D20,
    0x4E554C4C, 0x207C7C20, 0x68642D3E, 0x66726565, 0x2D3E7072, 0x6576203D, 0x3D204E55, 0x4C4C2069,
    0x6E202564, 0x0
};
static u32 fzgx_pool_data_lbl_801221C0_290[24] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x63656C6C, 0x2D3E6E65, 0x7874203D,
    0x3D204E55, 0x4C4C207C, 0x7C202863, 0x6861722A, 0x29206365, 0x6C6C202B, 0x2063656C, 0x6C2D3E73,
    0x697A6520, 0x3C202863, 0x6861722A, 0x29206365, 0x6C6C2D3E, 0x6E657874, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_2F0[15] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x30203C20, 0x66746F74, 0x616C2026,
    0x26206674, 0x6F74616C, 0x203C3D20, 0x68642D3E, 0x73697A65, 0x20696E20, 0x25640000
};
static u32 fzgx_pool_data_lbl_801221C0_32C[49] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F534368, 0x65636B48, 0x6561703A, 0x20466169, 0x6C656420, 0x746F7461, 0x6C203D3D, 0x2068642D,
    0x3E73697A, 0x6520696E, 0x20256400, 0xA4F5344, 0x756D7048, 0x65617028, 0x2564293A, 0xA000000,
    0x2D2D2D2D, 0x2D2D2D2D, 0x496E6163, 0x74697665, 0xA000000, 0x61646472, 0x973697A, 0x65090965,
    0x6E640970, 0x72657609, 0x6E657874, 0xA000000, 0x2D2D2D2D, 0x2D2D2D2D, 0x416C6C6F, 0x63617465,
    0x640A0000, 0x25780925, 0x64092578, 0x9257809, 0x25780A00, 0x2D2D2D2D, 0x2D2D2D2D, 0x46726565,
    0xA000000, 0x4E6F7420, 0x616C6C6F, 0x63617465, 0x20686561, 0x7020626C, 0x6F636B2E, 0x0,
    0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_801221C0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_801221C0;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_24;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_5C;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_84;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_D4;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_114;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_14C;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_198;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_1CC;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_20C;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_248;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_290;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_2F0;
    s = *(u8 *)fzgx_pool_data_lbl_801221C0_32C;
}
#pragma section code_type ".text"

extern Heap *lbl_801A6744;
extern s32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;
extern void OSReport(const char *, ...);
extern u32 fn_8000951C(u32);
extern u32 fn_800095A4(void);
/* Report a heap consistency failure (message at msg + off) and bail out. */
s32 fn_800090A4(s32 id) {
s32 freeTotal;
s32 size;
u32 lo;
u32 hi;
Heap *heap;
s32 total;
s32 usedTotal;
s32 avail;
HeapBlock *b;
HeapBlock *used;

freeTotal = 0;
usedTotal = 0;
avail = 0;
fn_8000951C(id);
if (lbl_801A6744 == ((void *)0) ) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0)), 0x350); fn_800095A4(); return -1; } ;
if (id < 0 || id >= lbl_801A6740) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_24)), 0x351); fn_800095A4(); return -1; } ;
heap = &lbl_801A6744[id];
size = heap->size;
if (size < 0) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_5C)), 0x354); fn_800095A4(); return -1; } ;
if (heap->free != ((void *)0) && heap->free->prev != ((void *)0) ) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_84)), 0x356); fn_800095A4(); return -1; } ;
lo = lbl_801A673C;
hi = lbl_801A6738;
for (b = heap->free; b != ((void *)0) ; b = b->next) {
if (lo > (u32)b || (u32)b >= hi) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_D4)), 0x359); fn_800095A4(); return -1; } ;
if ((u32)b & 0x1f) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_114)), 0x35a); fn_800095A4(); return -1; } ;
if (b->next != ((void *)0) && b->next->prev != b) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_14C)), 0x35b); fn_800095A4(); return -1; } ;
if (b->size < 0x40) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_198)), 0x35c); fn_800095A4(); return -1; } ;
if (b->size & 0x1f) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_1CC)), 0x35d); fn_800095A4(); return -1; } ;
freeTotal += b->size;
if (freeTotal <= 0 || freeTotal > size) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_20C)), 0x360); fn_800095A4(); return -1; } ;
}
used = heap->used;
if (used != ((void *)0) && used->prev != ((void *)0) ) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_248)), 0x368); fn_800095A4(); return -1; } ;
for (; used != ((void *)0) ; used = used->next) {
if (lo > (u32)used || (u32)used >= hi) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_D4)), 0x36b); fn_800095A4(); return -1; } ;
if ((u32)used & 0x1f) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_114)), 0x36c); fn_800095A4(); return -1; } ;
if (used->next != ((void *)0) && used->next->prev != used) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_14C)), 0x36d); fn_800095A4(); return -1; } ;
if (used->size < 0x40) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_198)), 0x36e); fn_800095A4(); return -1; } ;
if (used->size & 0x1f) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_1CC)), 0x36f); fn_800095A4(); return -1; } ;
if (used->next != ((void *)0) && (u32)used + used->size >= (u32)used->next) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_290)), 0x370); fn_800095A4(); return -1; } ;
usedTotal += used->size;
avail += used->size - 0x20;
if (usedTotal <= 0 || usedTotal > size) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_2F0)), 0x374); fn_800095A4(); return -1; } ;
}
total = usedTotal + freeTotal;
if (total != size) { OSReport((const char *)(((u8 *)fzgx_pool_data_lbl_801221C0_32C)), 0x37c); fn_800095A4(); return -1; } ;
fn_800095A4();
return avail;
}
