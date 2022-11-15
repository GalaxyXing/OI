#include<cstdio>
int dp[8][(1<<8)];
int map[8][8];
bool g[1<<8];
int max(int x,int y){return x>y?x:y;}
int main(){
    int q;scanf("%d",&q);
    for(int i=0;i<(1<<6);i++)if(!(i&(i<<1))&&!(i&(i>>1))) g[i]=1;
    while(q--){
        int n,m,ans=0;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&map[i][j]);    
        for(int i=1;i<=n;i++)for(int j=0;j<(1<<m);j++)dp[i][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<m);j++){
                if(g[j]){
                    for(int k=0;k<(1<<m);k++){
                        if(!(j&k)&&!(j&(k>>1))&&!(j&(k<<1)))
                        dp[i][j]=max(dp[i][j],dp[i-1][k]);
                    }
                    int tmp=j,res=0;
                    for(int cur=m;cur>=1;cur--){
                        res+=(tmp&1)*map[i][cur];
                        tmp>>=1;
                    }
                    dp[i][j]+=res;
                }
            }
        }
        for(int i=0;i<(1<<m);i++)ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}