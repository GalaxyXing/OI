#include <cstdio>
int n,m,L,rock[50005];
bool check(int x){
    int cur=0,cnt=0;
    for(int i=1;i<=n;i++)(rock[i]-cur<x)?cnt++:cur=rock[i];
    return cnt<=m;
}
int main(){
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",rock+i);
    int l=1,r=L+1,mid;
    while(r-l>1)mid=r+l>>1,check(mid)?l=mid:r=mid;
    return printf("%d",l),0;
}