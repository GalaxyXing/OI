#include<cstdio>
int n,m,l[200005],r[200005],w[200005],v[200005],minw=2e6+10,cnt[200005];
long long sum[200005],s,alls;
inline int min(int x,int y){return x<y?x:y;}
inline long long minl(long long x,long long y){return x<y?x:y;}
inline long long abs(long long x){return x>0?x:-x;}
long long check(long long x){
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(w[i]>=x?v[i]:0),cnt[i]=cnt[i-1]+(w[i]>=x);
    long long cntt=0;
    for(int i=1;i<=m;i++)cntt+=(sum[r[i]]-sum[l[i]-1])*(cnt[r[i]]-cnt[l[i]-1]);
   // printf("x%lld cntt%lld\n",x,cntt);
    return cntt;
}
int main(){
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++)scanf("%d%d",w+i,v+i),alls+=v[i],minw=min(minw,w[i]);
    for(int i=1;i<=m;i++)scanf("%d%d",l+i,r+i);
    long long L=0,R=alls+1,mid;
    while(R-L>1)mid=(R+L)>>1,(check(mid)>s)?L=mid:R=mid;
  //  printf("L%lld R%lld\n",L,R);
    long long ansR=abs(check(R)-s),ansL=abs(check(L)-s);
   // printf("ansR %lld ansL %lld\n",ansR,ansL);
    printf("%lld",minl(ansR,ansL));
    return 0;
}