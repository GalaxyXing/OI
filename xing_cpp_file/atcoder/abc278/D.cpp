#include<bits/extc++.h>
using i8=char;    using u8=unsigned char;    using i16=short;    using u16=unsigned short;
using i32=int;    using u32=unsigned int;    using i64=long long;using u64=unsigned long long;
using i128=__int128;using u128=unsigned __int128;using f32=float;using f64=double;using f128=long double;
template<typename T> inline void read(T &x){
    char ch=getchar(),f=0;x=0;while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')(x=x*10+(ch-'0')),ch=getchar();x=(f?-x:x);
}
template<typename T,typename ...Ts> void read(T &x,Ts &...xs){read(x); read(xs...); }
char fostk[50]; u8 cntfostk;
template<typename T> inline void write(T x){
    if(x<0)putchar('-'),x=-x;while(x>9)fostk[++cntfostk]='0'+x%10,x/=10;
    fostk[++cntfostk]=x+'0'; while(cntfostk)putchar(fostk[cntfostk--]);
}
template<typename T> void writesp(T x){write(x); putchar(' '); }
template<typename T> void writeln(T x){write(x); putchar('\n'); }
template<typename T> void writelns(T x){writeln(x); }
template<typename T,typename ...Ts> void write(T x,Ts ...xs){writesp(x); write(xs...); }
template<typename T,typename ...Ts> void writeln(T x,Ts ...xs){write(x,xs...); putchar('\n'); }
template<typename T,typename ...Ts> void writelns(T x,Ts ...xs){writeln(x); writelns(xs...); }
#define i32 i64
i32 a[200005],n;
namespace SegTree{
    #define mid ((l+r)>>1)
    struct Node{
        i32 lz,a;
    }nod[200005<<2];
    inline i32 ls(i32 x){
        return x<<1;
    }
    inline i32 rs(i32 x){
        return x<<1|1;
    }
    void build(i32 x,i32 l,i32 r){
        if(l==r)nod[x].a=::a[l];
        else{
            build(ls(x),l,mid);
            build(rs(x),mid+1,r);
        }
    }
    void assign(i32 x,i32 l,i32 r,i32 v){
        nod[x].lz=v;
        nod[x].a=v;
    }
    void push_down(i32 x,i32 l,i32 r){
        if(nod[x].lz){
            assign(ls(x),l,mid,nod[x].lz);
            assign(rs(x),mid+1,r,nod[x].lz);
            nod[x].lz=0;
        }
    }
    void modify(i32 x,i32 l,i32 r,i32 ml,i32 mr,i32 k){
        if(ml<=l&&r<=mr)assign(x,l,r,k);
        else{
            push_down(x,l,r);
            modify(ls(x),l,mid,ml,mr,k);
            modify(rs(x),mid+1,r,ml,mr,k);
        }
    }
    void add(i32 x,i32 l,i32 r,i32 pos,i32 k){
        if(l==r)nod[x].a+=k;
        else {
            push_down(x,l,r);
            if(pos<=mid)add(ls(x),l,mid,pos,k);
            else add(rs(x),mid+1,r,pos,k);
        }
    }
    i32 query(i32 x,i32 l,i32 r,i32 pos){
        if(l==r)return nod[x].a;
        push_down(x,l,r);
        if(pos<=mid)return query(ls(x),l,mid,pos);
        else return query(rs(x),mid+1,r,pos);
    }
    #undef mid
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        freopen("test.err","w",stderr);
    #endif
    read(n);
    for(i32 i=1;i<=n;i++){
        read(a[i]);
    }
    SegTree::build(1,1,n);
    i32 q;
    read(q);
    for(i32 i=1;i<=q;i++){
        i32 opt,x;
        read(opt,x);
        if(opt==1){
            SegTree::modify(1,1,n,1,n,x);
        }else if(opt==2){
            i32 y;
            read(y);
            SegTree::add(1,1,n,x,y);
        }else{
            writeln(SegTree::query(1,1,n,x));
        }
    }
    return 0;
}