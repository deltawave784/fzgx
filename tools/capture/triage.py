"""triage.py SYM BODY MW [FLAGS]: residual rows + captured named/pool webs + callee-saved pop order."""
import sys, json, subprocess
import paths
sys.path.insert(0,str(paths.MWCC/'tools'/'replay')); sys.path.insert(0,str(paths.MWCC/'tools'))
from pathlib import Path
from fzgx.project import Project
from fzgx import oracle, stuck
import simplify_replay as sr
S=paths.CAPTURE
sym,body,mw=sys.argv[1:4]; fl=sys.argv[4] if len(sys.argv)>4 else None
p=Project(); res=oracle.check(p,sym,0,source=Path(body),mw_version=mw,extra_cflags=fl)
a=stuck.analyse(p,sym,body,res)
print(f'== {sym} {res.percent:.2f} {a["counts"]}')
for i,l,r in a['diffs'][:12]: print(f'{i:5} | {l:40} | {r}')
cap=f'{S}/{sym}'
out=subprocess.run(paths.mwcc_tool(str(paths.MWCC/'tools'/'vreg_map.py'),cap,'0001'),capture_output=True,text=True,cwd=paths.MWCC).stdout
for ln in out.split('\n'):
    f=ln.split()
    if len(f)>=5 and (f[1]!='?' or f[4] in ('r14','r15','r16','r17','r18','r19','r20','r21','r22','r23','r24','r25','r26','r27','r28','r29','r30','r31')): print('  '+ln)
before,after=sr.load(cap,'0001'); pop,color=sr.replay(before)
print('  callee-saved pops:', ', '.join(f'{v}->r{color[v]}' for v in pop if 14<=color[v]<=31))
