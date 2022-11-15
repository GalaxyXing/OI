#include<cstdio>
#include<algorithm>
int n,m;
int xx[100005],xs[100005];
int min(int x,int y){return x<y?x:y;}
int abs(int x){return x>0?x:-x;}
int solve(int x){
    int l=1,r=m+1,mid;
    while(r-l>1)mid=l+r>>1,(xx[mid]>x)?r=mid:l=mid;
    return min(abs(xx[r]-x),abs(xx[l]-x));
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)scanf("%d",xx+i);
    for(int i=1;i<=n;i++)scanf("%d",xs+i);
    std::sort(xx+1,xx+1+m);
    long long ans=0;
    for(int i=1;i<=n;i++)ans += solve(xs[i]);
    printf("%lld",ans);
    return 0;
}