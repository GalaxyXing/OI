#include<cstdio>
int dp[15][(1<<14)];
const int mod=100000000;
int map[13][13];
int zt[13],ans;
bool g[1<<13];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)scanf("%d",&map[i][j]),map[i][j]^=1;
        for(int j=1;j<=m;j++)zt[i]=((zt[i]<<1)|map[i][j]);
    }
    // for(int i=1;i<=n;i++)printf("%d ",zt[i]);
    // printf("\n");
    for(int i=0;i<(1<<m);i++)if(!(i&(i<<1))&&!(i&(i>>1))) g[i]=1;
    // for(int i=0;i<(1<<m);i++)printf("%d ",g[i]);
    // printf("\n");
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<m);j++){
            if(g[j]&&!(j&zt[i])){
                for(int k=0;k<(1<<m);k++){
                    if(!(j&k))
                    dp[i][j]+=dp[i-1][k];
                   // dp[i][j]%=mod;
                }
            }
        }
    }
    for(int i=0;i<(1<<m);i++)ans+=dp[n][i];
    printf("%d",ans%mod);
    return 0;
}