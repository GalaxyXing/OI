#include<cstdio>
#include<algorithm>
int n,c,maxdis;
int barn[100005];
int max(int x,int y){return x>y?x:y;}
bool check(int x){
    int now=barn[1],cnt=1;
    for(int i=2;i<=n;i++)(barn[i]-now>=x)?now=barn[i],cnt++:0;
    return cnt>=c;
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",barn+i),maxdis=max(maxdis,barn[i]);
    std::sort(barn+1,barn+1+n);
    int l=1,r=maxdis+1,mid;
    while(r-l>1)mid=l+r>>1,check(mid)?l=mid:r=mid;
    printf("%d",l);
    return 0;
}