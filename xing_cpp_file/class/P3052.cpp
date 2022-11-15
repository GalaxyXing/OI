#include<cstdio>
int n,w[20],allw,dp[(1<<18)+5],cntw[(1<<18)+5];
inline int min(int x,int y){return x<y?x:y;}
int main(){
    scanf("%d %d",&n,&allw);
    for(int i=0;i<n;i++){
        scanf("%d",w+i);
        cntw[1<<i]=w[i];
    }
    for(int i=0;i<(1<<n);i++)cntw[i]=cntw[i&(i-1)]+cntw[i^(i&(i-1))];
    for(int i=1;i<(1<<n);i++){
        if(cntw[i]<=allw)dp[i]=1;
        else for(int j=i;j;j=(i&(j-1))){
            dp[i]=((dp[i]==0)?dp[j]+dp[i^j]:min(dp[i],dp[j]+dp[i^j]));
        }
    }
    printf("%d",dp[(1<<n)-1]);
    return 0;
} 