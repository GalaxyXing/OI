#include<cstdio>
int n,k;
double sz[10005],maxsz;
double max(double x,double y){return x>y?x:y;}
bool check(double x){
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=(int)(sz[i]/x);
    return cnt>=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lf",sz+i),maxsz=max(maxsz,sz[i]);
    double l=0.01,r=maxsz+1,mid;
    while(r-l>0.01)mid=(l+r)/2,check(mid)?l=mid:r=mid;
    printf("%lf",l);
    return 0;
}