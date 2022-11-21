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
std::vector<i32> G[105],DAG[105];
struct Node{
    i32 v,w,dfn,low,bel;
    static i32 cntdfn;
    bool ins;
}nod[105];
struct Scc{
    i32 v,w,in;
    static i32 cntscc;
}scc[105];
i32 Node::cntdfn=0,Scc::cntscc=0,n,m;
std::stack<i32> s;
void tarjan(i32 x){
    nod[x].dfn=++Node::cntdfn;
    nod[x].low=nod[x].dfn;
    nod[x].ins=true;
    s.push(x);
    for(auto v:G[x]){
        if(!nod[v].dfn){
            tarjan(v);
            nod[x].low=std::min(nod[x].low,nod[v].low);
        }else if(nod[v].ins)nod[x].low=std::min(nod[x].low,nod[v].low);
    }
    if(nod[x].dfn==nod[x].low){
        i32 now=++Scc::cntscc,y;
        do{
            y=s.top();
            s.pop();
            scc[now].v+=nod[y].v;
            scc[now].w+=nod[y].w;
            nod[y].bel=now;
            nod[y].ins=false;
        }while(x!=y);
    }
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        freopen("test.err","w",stderr);
    #endif
    read(n,m);
    for(i32 i=1;i<=n;i++)read(nod[x].w);
    for(i32 i=1;i<=n;i++)read(nod[x].v);
    for(i32 i=1;i<=n;i++){
        i32 u;
        G[u].push_back(i);
    }
    for(i32 i=1;i<=n;i++)if(!nod[i].dfn)tarjan(i);
    for(i32 i=1;i<=n;i++){
        for(auto v:G[i]){
            if(nod[v].bel==nod[i].bel)continue;
            DAG[nod[i].bel].push_back(nod[v].bel);
            scc[nod[v].bel].in++;
        }
    }
    for(i32 i=1;i<=Scc::cntscc;i++){
        if(!scc[i].in)DAG[0].push_back(i);
    }
    return 0;
}