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
i32 a[200005],b[200005];
i32 n;
u64 calc(){
    i32 sum=0;
    u64 re=0;
    for(i32 i=1;i<=n;i++){
        sum+=b[i];
        if(b[i]==0)re+=sum;
    }
    return re;
}
void solve(){
    read(n);
    for(i32 i=1;i<=n;i++){
        read(a[i]);
        b[i]=a[i];
    }
    u64 ans=calc();
    for(i32 i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            break;
        }
    }
    ans=std::max(calc(),ans);
    for(i32 i=1;i<=n;i++)b[i]=a[i];
    for(i32 i=n;i>=1;i--){
        if(b[i]==1){
            b[i]=0;
            break;
        }
    }
    ans=std::max(calc(),ans);
    writeln(ans);
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        freopen("test.err","w",stderr);
    #endif
    i32 t;
    read(t);
    while(t--){
        solve();
    }
    return 0;
}