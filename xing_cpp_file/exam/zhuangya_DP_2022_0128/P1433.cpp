#include<cstdio>
#include<cmath>
#define INF 0x7fffffff
int n;
struct CHESSE{
    double x,y;
}ch[20];
double dp[20][(1<<16)+5];
double min(double x,double y){return x<y?x:y;}
double dis(CHESSE a,CHESSE b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&ch[i].x,&ch[i].y);
    for(int i=0;i<=n;i++)for(int j=0;j<(1<<n);j++)dp[i][j]=INF;
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if(!(i&(1<<(j-1))))continue;
            if(i==(1<<(j-1)))dp[j][i]=0;
            else{
                for(int k=1;k<=n;k++){
                    if(!(i&(1<<(k-1))))continue;
                    if(j==k)continue;
                    dp[j][i]=min(dp[j][i],dp[k][i-(1<<(j-1))]+dis(ch[j],ch[k]));
                }
            }
        }
    }
    double ans=INF;
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[i][(1<<n)-1]+dis(ch[0],ch[i]));
    }
    printf("%.2lf",ans);
    return 0;
}