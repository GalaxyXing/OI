#include<cstdio>
int W,n,t[20],w[20],dp[(1<<16)+5],tm[(1<<16)+5],wm[(1<<16)+5];
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
int main(){
    scanf("%d%d",&W,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",t+i,w+i);
    }
    for(int i=1;i<(1<<n);i++)dp[i]=0x7fffffff;
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
            if(i&(1<<(j-1)))
                tm[i]=max(tm[i],t[j]),wm[i]+=w[j];//初始化最大time,weight;
 //   for(int i=0;i<(1<<n);i++)printf("%d %d\n",tm[i],wm[i]);
    for(int i=0;i<(1<<n);i++)
        for(int j=i;j;j=(j-1)&i)
            if(wm[j]<=W)
                dp[i]=min(dp[i],dp[i^j]+tm[j]);  
 //   for(int i=0;i<(1<<n);i++)printf("%d\n",dp[i]); 
    printf("%d",dp[(1<<n)-1]);
    return 0;
}