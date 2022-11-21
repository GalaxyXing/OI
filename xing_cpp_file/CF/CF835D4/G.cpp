#include<bits/stdc++.h>
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
struct Edge{
    i32 v,w;
};
std::vector<Edge> G[100005];
std::set<i32> s;
i32 n,a,b;
i32 dp[100005][2];
void dfs(i32 x,i32 fa,i32 mode){
    for(auto e:G[x]){
        if(e.v==fa)continue;
        if(mode==0&&e.v==b)continue;
        // if(mode==1&&e.v==a)continue;
        dp[e.v][mode]=dp[x][mode]^e.w;
        dfs(e.v,x,mode);
    }
}
void solve(){
    read(n,a,b);
    s.clear();
    for(i32 i=1;i<=n;i++)G[i].clear();
    for(i32 i=1;i<n;i++){
        i32 u,v,w;
        read(u,v,w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(i32 i=1;i<=n;i++)dp[i][0]=0x3f3f3f3f3f3f3f3f;
    dp[a][0]=0;
    dfs(a,0,0);
    if(dp[b][0]==0){
        puts("YES");
        return;
    }
    for(i32 i=1;i<=n;i++){
        if(i==b)continue;
        if(dp[i][0]==0x3f3f3f3f3f3f3f3f)continue;
        s.insert(dp[i][0]);
    }
    // for(i32 i=1;i<=n;i++){
    //     printf("dp[i:%d][0]:%d\n",i,dp[i][0]);
    // }
    for(i32 i=1;i<=n;i++)dp[i][1]=0x3f3f3f3f3f3f3f3f;
    dp[b][1]=0;
    dfs(b,0,1);
    // for(i32 i=1;i<=n;i++){
    //     printf("dp[i:%d][1]:%d\n",i,dp[i][1]);
    // }
    for(i32 i=1;i<=n;i++){
        if(i==b)continue;
        if(dp[i][1]==0x3f3f3f3f3f3f3f3f)continue;
        if(s.find(dp[i][1])!=s.end()){
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        freopen("test.err","w",stderr);
    #endif
    i32 t=0;
    read(t);
    while(t--){
        solve();
    }
    return 0;
}