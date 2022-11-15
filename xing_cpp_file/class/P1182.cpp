#include<cstdio>
int N,M,a[100005];
long long all,maxa;
long long max(long long a,long long b){return (a>b?a:b);}
long long min(long long x,long long y){return x<y?x:y;}
int check(long long x){
    long long cnt=0,cntseg=1;
    for(int i=1;i<=N;i++)(cnt+a[i]>x)?cntseg++,cnt=a[i]:cnt+=a[i];
    return cntseg;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)scanf("%d",a+i),all+=a[i],maxa=max(maxa,(long long)a[i]);
    long long l=max(all/(M),maxa-1),r=(long long)1e9+10,mid;
    while(r-l>1)
        mid=l+r>>1,
        check(mid)<=M?r=mid:l=mid;
    return printf("%lld",r),0;
}