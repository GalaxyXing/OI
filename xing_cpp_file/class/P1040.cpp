#include<cstdio>
int n;
long long dp[40][40];
int dppath[40][40][40];
int score[40];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",score+i);
        dp[i][i]=score[i];
        dp[i][i-1]=1;
        dppath[i][i][1]=i;
    }
    dp[n+1][n]=1;
    for(int l=2;l<=n;l++){//³¤¶È
        for(int i=1,j=l+i-1;j<=n;i++,j=l+i-1){
         //   printf("%d %d\n",i,j);
            for(int k=i;k<=j;k++){
                if(dp[i][k-1]*dp[k+1][j]+score[k]>dp[i][j]){
                    dp[i][j]=dp[i][k-1]*dp[k+1][j]+score[k];
                    dppath[i][j][1]=k;
                    for(int p=i;p<=k-1;p++)dppath[i][j][p-i+2]=dppath[i][k-1][p-i+1];                    
                    for(int p=k+1;p<=j;p++)dppath[i][j][p-i+1]=dppath[k+1][j][p-k];
                }
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    for(int i=1;i<=n;i++){
        printf("%d ",dppath[1][n][i]);
    }
    return 0;
}