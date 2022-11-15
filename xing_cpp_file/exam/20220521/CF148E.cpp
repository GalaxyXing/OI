#include<cstdio>
using namespace std;
inline int read(){
    int re=0;
    char t=getchar();
    while(t<'0'||t>'9')t=getchar();
    while(t>='0'&&t<='9')re=(re<<3)+(re<<1)+(t^48),t=getchar();
    return re;
}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
int n,m;
int shelf[105][105],obj[105][105],flor[105],suml[105][105],sumr[105][105],dp[105][10005];
signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        flor[i]=read();
        for(int j=1;j<=flor[i];j++){
            obj[i][j]=read();
        }
        for(int j=1;j<=flor[i];j++){
            suml[i][j]=suml[i][j-1]+obj[i][j];
        //    printf("i %d j %d suml %d\n",i,j,suml[i][j]);
        }
        for(int j=flor[i];j>=1;j--){
            sumr[i][j]=sumr[i][j+1]+obj[i][j];
        //    printf("i %d j %d sumr %d\n",i,j,sumr[i][j]);
        }
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=flor[i];j++){
            for(int k=0;k<=j;k++){
                shelf[i][j]=max(shelf[i][j],suml[i][k]+sumr[i][flor[i]+1-(j-k)]);
            }
         //   printf("i %d j %d shelf %d\n",i,j,shelf[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(flor[i],m);j++){
            for(int k=m;k>=j;k--){
                dp[i][k]=max(dp[i][k],dp[i-1][k-j]+shelf[i][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("i %d j %d dp %d\n",i,j,dp[i][j]);
    //     }
    // }
    printf("%d",dp[n][m]);
    return 0;

}