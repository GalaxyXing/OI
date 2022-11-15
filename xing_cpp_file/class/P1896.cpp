#include<cstdio>
long long dp[12][(1<<10)+1][100];
bool g[(1<<10)];
int cnt[(1<<10)];
int n,k;
long long ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<(1<<n);i++){
        if(!(i&(i<<1))&&!(i&(i>>1)))g[i]=1;
        for(int j=0;j<n;j++){
            if((i&(1<<j))==(1<<j))cnt[i]++;
        }
    }
    // for(int i=0;i<(1<<n);i++){
    //     printf("g%d cnt%d i%d\n",g[i],cnt[i],i);
    // }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<n);j++){
            if(g[j]){
                 for(int m=0;m<(1<<n);m++){
                     if(!g[m])continue;
                     if(!(j&m)&&!(m&(j<<1))&&!(m&(j>>1))){
                         for(int s=cnt[j];s<=k;s++){
                             dp[i][j][s]+=dp[i-1][m][s-cnt[j]];
                         }
                     }
                 }
                //  for(int m=0;m<=k;m++){
                //     printf("i%d j%d m%d dp%d\n",i,j,m,dp[i][j][m]);
                //  }printf("\n");
            }
        }

    }
    for(int i=0;i<(1<<n);i++){
        ans+=dp[n][i][k];
    }
    printf("%lld",ans);
    return 0;
}