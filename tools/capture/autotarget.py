"""autotarget.py SYM BODY MW [FLAGS]: map residual register rows to captured webs and print solver targets.

Both register classes are mapped: GPR rows (`rN`, operand class 4) and FPR rows (`fN`, operand class 3).
The solver runs once per class that has targets (`--class gpr|fpr`)."""
import sys, json, re, subprocess
import paths
from pathlib import Path
from fzgx.project import Project
from fzgx import oracle, stuck
S=paths.CAPTURE
sym,body,mw=sys.argv[1:4]; fl=sys.argv[4] if len(sys.argv)>4 else None
cap=f'{S}/{sym}'
p=Project(); res=oracle.check(p,sym,0,source=Path(body),mw_version=mw,extra_cflags=fl)
if not res.ok:
    print(f'{sym}: check failed: {res.error[-400:]}'); sys.exit(1)
l,r=res._rows
import glob as _glob
_O=[k for k in range(len(r)) if stuck._fmt(r[k])]
_best=None
for _f in sorted(_glob.glob(f'{cap}/pcode-*-final.json')):
    _d=json.load(open(_f)); _n=sum(len(b['instructions']) for b in _d['blocks'])
    if _best is None or abs(_n-len(_O))<abs(_best[0]-len(_O)): _best=(_n,_f)
idx=paths.capture_index(cap,sym,_best[1].split('pcode-')[1].split('-')[0])
fin=json.load(open(f'{cap}/pcode-{idx}-final.json')); sch=json.load(open(f'{cap}/pcode-{idx}-scheduled.json'))
byaddr={i['address']:i for b in sch['blocks'] for i in b['instructions']}
F=[i for b in fin['blocks'] for i in b['instructions']]
O=[(k,stuck._fmt(r[k])) for k in range(len(r)) if stuck._fmt(r[k])]
print(f'{sym} {res.percent:.2f}: object rows {len(O)}, final pcode {len(F)}')
n=min(len(O),len(F)); mism=[k for k in range(n) if O[k][1].split(' ')[0].split('.')[0].lower()!=F[k]['opcode_descriptor']['mnemonic'].lower().rstrip('.')]
print('mnemonic mismatches (first 8):', [(k,O[k][1].split(' ')[0],F[k]['opcode_descriptor']['mnemonic']) for k in mism[:8]])
# operand class of a register operand (kind 0): 4 = GPR, 3 = FPR (the 1.2.5/1.3.2 operand layout)
CLASSES={'gpr':(r'\br(\d+)\b',4,'r'),'fpr':(r'\bf(\d+)\b',3,'f')}
for cls,(rx,opclass,prefix) in CLASSES.items():
    targets={}; conflicts=[]
    for k in range(n):
        row_i,ours=O[k]; retail=stuck._fmt(l[row_i])
        if not retail or retail==ours or retail.split(' ')[0]!=ours.split(' ')[0]: continue
        ro=[int(x) for x in re.findall(rx,ours)]; rr=[int(x) for x in re.findall(rx,retail)]
        if len(ro)!=len(rr) or ro==rr: continue
        gops=[o for o in F[k]['operands'] if o.get('kind')==0 and o.get('class')==opclass]
        sops=[o for o in byaddr[F[k]['address']]['operands'] if o.get('kind')==0 and o.get('class')==opclass] if F[k]['address'] in byaddr else []
        if len(gops)!=len(ro) or len(sops)!=len(gops): continue
        for j,(a,b) in enumerate(zip(ro,rr)):
            if a==b: continue
            if gops[j]['reg']!=a: continue
            v=sops[j]['reg']
            if v in targets and targets[v]!=b: conflicts.append((v,targets[v],b))
            targets.setdefault(v,b)
    if not targets and not conflicts: continue
    print(f'[{cls}] targets:', ','.join(f'v{v}:{prefix}{c}' for v,c in sorted(targets.items())))
    print(f'[{cls}] conflicts:', conflicts[:8])
    bad={v for v,_,_ in conflicts}
    t=','.join(f'v{v}:{prefix}{c}' for v,c in sorted(targets.items()) if v not in bad)
    if not t: continue
    try:
        out=subprocess.run(paths.run_tool('-c',"import sys; sys.path[:0]=sys.argv.pop(1).split(chr(10)); import allocator_snapshot as a; a.SUPPORTED_TARGETS['132']='GC/1.3.2'; import source_rank_solver as s; sys.argv=['solver']+sys.argv[1:]; s.main()",chr(10).join(map(str,paths.TOOL_DIRS)),cap,str(int(idx)),'--class',cls,'--target',t,'--samples','1500','--max-permutations','20000'),capture_output=True,text=True,timeout=240)
        print(out.stdout[-2500:]); print(out.stderr[-600:])
    except subprocess.TimeoutExpired:
        print('status=timeout')
