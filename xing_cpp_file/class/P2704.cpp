#include<cstdio>
int map[105],n,m;
int zt[105],cntzt;
int cnt[105];
int dp[105][70][70],ans;
inline int max(int x,int y){return x>y?x:y;}
int main(){
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char tmp;
            scanf("\n%c",&tmp);
            if(tmp=='H')map[i]=(map[i]<<1)+1;
            else if(tmp=='P')map[i]<<=1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d %d\n",i,map[i]);
    // }
    for(int i=0;i<(1<<m);i++){
        if(!(i&(i<<1))&&!(i&(i>>1))&&!(i&(i<<2))&&!(i&(i>>2))){
            zt[++cntzt]=i;
            for(int j=0;j<m;j++){
                if((i&(1<<j))==(1<<j))cnt[cntzt]++;
            }
        }
    }
    // for(int i=1;i<=cntzt;i++){
    //     printf("%d %d %d\n",i,zt[i],cnt[i]);
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cntzt;j++){
            if(!(zt[j]&map[i])){
                if(i>1){
                    for(int k=1;k<=cntzt;k++){
                        if(i>2){
                            for(int s=1;s<=cntzt;s++){
                                if(!(zt[j]&zt[k])&&!(zt[j]&zt[s])){
                                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][s]+cnt[j]);
                                }
                            }
                        }
                        else {
                            if(!(zt[j]&zt[k]))dp[i][j][k]=dp[i-1][k][1]+cnt[j];
                        }
                    }
                }   
                else dp[i][j][1]=cnt[j];             
            }
        }
    }
    for(int i=1;i<=cntzt;i++){
        for(int j=1;j<=cntzt;j++){
            ans=max(ans,dp[n][i][j]);
        }
    }
    printf("%d",ans);
}
