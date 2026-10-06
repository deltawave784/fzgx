#include "types.h"
typedef struct MovieObject MovieObject;
typedef struct MovieVTable { u8 pad[0x24]; int (*get)(MovieObject *, int); } MovieVTable;
struct MovieObject { MovieVTable *vtable; };
typedef struct MovieEntry { int field_0; MovieObject *object; int field_8; int field_c; u8 pad[0x64]; } MovieEntry;
typedef struct MovieModule {
 u8 pad0[0x48]; int field_48; int field_4c; int field_50;
 u8 pad54[0x918]; int field_96c;
 u8 pad970[0x590]; int field_f00; int field_f04;
 u8 padf08[0x248]; MovieEntry entries[1];
 u8 pad11c4[0x974]; int field_1b38;
} MovieModule;
extern int fn_12_2D73C(MovieModule *, int);
extern int fn_12_2F1D0(MovieModule *, int);
extern int fn_12_21D30(MovieModule *, int);
extern int fn_12_21C00(MovieModule *, int);
extern int fn_12_2F1B4(MovieModule *, int);
extern int fn_12_2E714(MovieModule *, int *, int *);
extern unsigned int UTY_MulDiv(int, int, int);
extern int fn_12_2E42C(int, int, int, int);
static inline int blocked(MovieModule *module) {
 int i;
 if (fn_12_2D73C(module,5) && fn_12_2F1D0(module,6)) return 1;
 if (fn_12_2D73C(module,6) && fn_12_2F1D0(module,7)) return 1;
 for(i=0;i<8;i++) { if(fn_12_21D30(module,i)) return 1; }
 return 0;
}
static inline int limit(MovieModule *module) {
 MovieEntry *entry;
 int value;
 entry = &module->entries[module->field_1b38];
 value = entry->object->vtable->get(entry->object,1);
 if(value >= entry->field_c * 80 / 100 || value >= fn_12_2D73C(module,0x46)) return 1;
 return 0;
}
int fn_12_2BE3C(MovieModule *module) {
 int first;
 int second;
 int remaining;
 int total;
 if(!fn_12_2D73C(module,0x43)) return 0;
 if(!fn_12_2D73C(module,0xf)) return 0;
 if(module->field_50 != 0) return 0;
 if(module->field_48 != 4) return 0;
 if(blocked(module)) return 0;
 if(fn_12_2D73C(module,5)==1 && module->field_96c==0) return 0;
 if(fn_12_2D73C(module,6)==1 && fn_12_21C00(module,2)>0) return 0;
 if(fn_12_2F1B4(module,1) && fn_12_21C00(module,0)>0) return 0;
 if(fn_12_2D73C(module,5)==1 && limit(module)) return 0;
 fn_12_2E714(module,&first,&second);
 remaining = module->field_f00;
 total = module->field_f04;
 remaining -= UTY_MulDiv(fn_12_2D73C(module,0x44),total,1000000);
 if(first<=0 || remaining<=0) return 0;
 return fn_12_2E42C(first,second,remaining,total)==0;
}
