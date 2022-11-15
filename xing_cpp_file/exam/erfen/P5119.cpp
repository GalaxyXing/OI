#include<cstdio>
#include<algorithm>
int N,M,t[100005],C,tmax;
bool check(int x){
    int l=1,r=1,cnt=1,bus=0;
    for(;r<=N;r++){
        if(bus==C)bus=1,l=r,cnt++;
        else if(t[r]-t[l]<=x)bus++;
        else bus=1,cnt++,l=r;
        if(cnt>M)return 0;
    }
    return 1;
}
int max(int x,int y){return (x>y)?x:y;}
int main(){
    scanf("%d%d%d",&N,&M,&C);
    for(int i=1;i<=N;i++)scanf("%d",t+i),tmax=max(tmax,t[i]);
    std::sort(t+1,t+N+1);
    //for(int i=1;i<=N;i++)printf("%d",t[i]);
    int l=0,r=tmax,mid;
    while(r-l>1)mid=l+r>>1,check(mid)?r=mid:l=mid;
    printf("%d",r);
}