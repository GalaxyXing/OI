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
i32 H,W,N,h,w;
i32 sum[305][305][305],a[305][305],ans[305][305];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        freopen("test.err","w",stderr);
    #endif
    read(H,W,N,h,w);
    for(i32 i=1;i<=H;i++){
        for(i32 j=1;j<=W;j++){
            read(a[i][j]);
            for(i32 k=1;k<=N;k++){
                sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k];
            }
            sum[i][j][a[i][j]]++;
        }
    }
    for(i32 i=1;i<=H-h+1;i++){
        for(i32 j=1;j<=W-w+1;j++){
            i32 ii=i+h-1,jj=j+w-1;
            i32 tmp[305]={};
            // printf("ii:%d jj:%d\n",ii,jj);
            for(i32 k=1;k<=N;k++){
                i32 qaq=sum[ii][jj][k]-sum[i-1][jj][k]-sum[ii][j-1][k]+sum[i-1][j-1][k];
                // printf("qaq:%d sum[ii:%d][jj:%d][k:%d]:%d sum[i-1:%d][j:%d][k:%d]:%d sum[i:%d][j-1:%d][k:%d]:%d sum[i-1:%d][j-1:%d][k:%d]:%d\n",
                //     qaq,ii,jj,k,sum[ii][jj][k],i-1,j,k,sum[i-1][j][k],i,j-1,k,sum[i][j-1][k],i-1,j-1,k,sum[i-1][j-1][k]);
                tmp[k]=sum[H][W][k]-qaq;
                // printf("tmp[k:%d]:%d,sum[H][W][k:%d]:%d\n",k,tmp[k],k,sum[H][W][k]);
            }
            for(i32 k=1;k<=N;k++){
                if(tmp[k])ans[i][j]++;
            }
        }
    }
    for(i32 i=1;i<=H-h+1;i++){
        for(i32 j=1;j<=W-w+1;j++){
            writesp(ans[i][j]);
        }
        putchar('\n');
    }
    return 0;
}