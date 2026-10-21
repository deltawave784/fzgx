#include "types.h"

extern f32 lbl_801A6648[];
extern f32 lbl_801A664C[];
extern f64 __fabs(f64);
extern f64 __frsqrte(f64);
extern u32 lbl_800953D8[];
extern u32 lbl_801A6DE0;
extern double ldexp(double, int);

#define HI(x) (*(s32 *)&(x))
#define LO(x) (*((u32 *)&(x) + 1))
static const double bp[2] = {1.0, 1.5};
static const double dp_h[2] = {0.0, 5.84962487220764160156e-01};
static const double dp_l[2] = {0.0, 1.35003920212974897128e-08};
#define bp(k) bp[k]
#define dp_h(k) dp_h[k]
#define dp_l(k) dp_l[k]

static inline double pow_sqrt(double x) {
    if (x > 0.0) {
        double guess = __frsqrte(x);
        guess = 0.5*guess*(3.0-x*(guess*guess));
        guess = 0.5*guess*(3.0-x*(guess*guess));
        guess = 0.5*guess*(3.0-x*(guess*guess));
        guess = 0.5*guess*(3.0-x*(guess*guess));
        return x*guess;
    } else if (0.0 == x) {
        return 0.0;
    } else if (x) {
        return lbl_801A6648[0];
    } else {
        return lbl_801A664C[0];
    }
}

double fn_80086008(double x, double y) {
    double z,ax,z_h,z_l,p_h,p_l;
    double y1,t1,t2,r,s,t,u,v,w,magnitude;
    s32 i,j,k,yisint,n,sign;
    s32 hx,hy,ix,iy;
    u32 lx,ly;

    hx = HI(x); lx = LO(x);
    hy = HI(y); ly = LO(y);
    ix = ((0x7fffffff) & (hx));
    iy = ((0x7fffffff) & (hy));
    if ((iy|ly)==0) return 1.0;
    if (ix > 0x7ff00000 || ((ix==0x7ff00000)&&(lx!=0)) ||
        iy > 0x7ff00000 || ((iy==0x7ff00000)&&(ly!=0))) return x+y;

    yisint = 0;
    if (hx < 0) {
        if (iy >= 0x43400000) yisint = 2;
        else if (iy >= 0x3ff00000) {
            k = (iy>>20)-0x3ff;
            if (k > 20) {
                j = ly>>(52-k);
                if ((u32)(j<<(52-k))==ly) yisint = 2-(((1) & (j)));
            } else if (ly==0) {
                j = iy>>(20-k);
                if ((j<<(20-k))==iy) yisint = 2-(((1) & (j)));
            }
        }
    }
    if (ly==0) {
        if (iy==0x7ff00000) {
            if (((ix-0x3ff00000)|lx)==0) return y-y;
            else if (ix >= 0x3ff00000)
                return (hy>=0)? y:0.0;
            else return (hy<0)?-y:0.0;
        }
        if (iy==0x3ff00000) {
            if (hy<0) return 1.0/x;
            else return x;
        }
        if (hy==0x40000000) return x*x;
        if (hy==0x3fe00000) {
            if (hx>=0) return pow_sqrt(x);
        }
    }
    magnitude = __fabs(x);
    ax = magnitude;
    if (lx==0) {
        if (ix==0x7ff00000 || ix==0 || ix==0x3ff00000) {
            z=magnitude;
            if (hy<0) z=1.0/z;
            if (hx<0) {
                if (((ix-0x3ff00000)|yisint)==0) z=(z-z)/(z-z);
                else if (yisint==1) z=-z;
            }
            return z;
        }
    }
    sign = (hx>>31)+1;
    if ((sign|yisint)==0) {
        lbl_801A6DE0=33;
        return lbl_801A6648[0];
    }
    if (iy>0x41e00000) {
        if (iy>0x43f00000) {
            if (ix<=0x3fefffff) return (hy<0)?1.0e300*1.0e300:1.0e-300*1.0e-300;
            if (ix>=0x3ff00000) return (hy>0)?1.0e300*1.0e300:1.0e-300*1.0e-300;
        }
        if (ix<0x3fefffff) return (hy<0)?1.0e300*1.0e300:1.0e-300*1.0e-300;
        if (ix>0x3ff00000) return (hy>0)?1.0e300*1.0e300:1.0e-300*1.0e-300;
        t=x-1.0;
        w=(t*t)*(0.5-t*(0.3333333333333333333333-t*0.25));
        u=1.44269502162933349609*t;
        v=t*1.92596299112661746887e-08-w*1.44269504088896338700;
        t1=u+v;
        LO(t1)=0;
        t2=v-(t1-u);
    } else {
        double s2,s_h,s_l,t_h,t_l;
        n=0;
        if (ix<0x00100000) {
            ax*=9007199254740992.0;
            n-=53;
            ix=HI(ax);
        }
        n+=(ix>>20)-0x3ff;
        j=((0x000fffff) & (ix));
        ix=j|0x3ff00000;
        if (j<=0x3988e) k=0;
        else if (j<0xbb67a) k=1;
        else { k=0; n+=1; ix-=0x00100000; }
        HI(ax)=ix;
        u=ax-bp(k);
        v=1.0/(ax+bp(k));
        s=u*v;
        s_h=s;
        LO(s_h)=0;
        t_h=0.0;
        HI(t_h)=((ix>>1)|0x20000000)+0x00080000+(k<<18);
        t_l=ax-(t_h-bp(k));
        s_l=v*((u-s_h*t_h)-s_h*t_l);
        s2=s*s;
        r=s2*s2*(0.599999999999994648725+ s2*(0.428571428578550166932+ s2*(0.333333329818377429507+ s2*(0.272728123808534+ s2*(0.23066074577556175+ s2*0.20697501780033842)))));
        r+=s_l*(s_h+s);
        s2=s_h*s_h;
        t_h=3.0+s2+r;
        LO(t_h)=0;
        t_l=r-((t_h-3.0)-s2);
        u=s_h*t_h;
        v=s_l*t_h+t_l*s;
        p_h=u+v;
        LO(p_h)=0;
        p_l=v-(p_h-u);
        z_h=0.961796700954437255859*p_h;
        z_l=dp_l(k)+(-7.02846165095275826516e-09*p_h+p_l*0.9617966939259756);
        t=(double)n;
        t1=(((z_h+z_l)+dp_h(k))+t);
        LO(t1)=0;
        t2=z_l-(((t1-t)-dp_h(k))-z_h);
    }
    s=1.0;
    if ((sign| (yisint-1))==0) s=-1.0;
    y1=y;
    LO(y1)=0;
    p_l=(y-y1)*t1+y*t2;
    p_h=y1*t1;
    z=p_l+p_h;
    j=HI(z);
    i=LO(z);
    if (j>=0x40900000) {
        if (((j-0x40900000)|i)!=0) return s*1.0e300*1.0e300;
        else if (p_l+8.0085662595372944372e-17>z-p_h) return s*1.0e300*1.0e300;
    } else if ((((0x7fffffff) & (j)))>=0x4090cc00) {
        /* j - its fixed address (the high word of -1075.0), spelled as an unsigned add */
        if (((j+0x3f6f3400)|i)!=0) return s*1.0e-300*1.0e-300;
        else if (p_l<=z-p_h) return s*1.0e-300*1.0e-300;
    }
    i=((0x7fffffff) & (j));
    k=(i>>20)-0x3ff;
    n=0;
    if (i>0x3fe00000) {
        n=j+(0x00100000>>(k+1));
        i=((0x000fffff) & (n));
        k=((((0x7fffffff) & (n)))>>20)-0x3ff;
        t=0.0;
        HI(t)=n & ~(u32)(0x000fffff>>k);
        n=(i|0x00100000)>>(20-k);
        if (j<0) n=-n;
        p_h-=t;
    }
    t=p_l+p_h;
    LO(t)=0;
    u=t*0.693147182464599609375;
    z_l=t*(-1.90465429995776804525e-09);
    v=(p_l-(t-p_h))*0.693147180559945309417+z_l;
    z=u+v;
    w=v-(z-u);
    t=z*z;
    t1=z-t*(0.166666666666666019+ t*(-0.0027777777777015593+ t*(0.00006613756321437934+ t*(-0.0000016533902205465252+ t*0.000000041381367970572385))));
    r=(z*t1)/(t1-2.0)-(w+z*w);
    z=1.0-(r-z);
    j=HI(z);
    j+=(n<<20);
    if ((j>>20)<=0) z=ldexp(z,n);
    else HI(z)+=(n<<20);
    return s*z;
}
