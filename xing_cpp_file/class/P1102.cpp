#include <cstdio>
#include"algorithm"
int a[200005],b[200005],c,n;
long long ans;
int cnt(int x){
    long long l=1,r=n+1,mid,ansr;
    while(r-l>1)mid=r+l>>1,a[mid]>x?r=mid:l=mid;
    if(a[l]!=x)return 0;
    ansr=l,l=0,r=n;
    while(r-l>1)mid=r+l>>1,a[mid]<x?l=mid:r=mid;
    return ansr-l;
}
int main(){
    freopen("P1102_3.in","r",stdin);
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",a+i),b[i]=a[i]+c;
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)ans+=cnt(b[i]); 
    printf("%lld",ans);
    return 0;
}