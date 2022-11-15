#include<iostream>
using namespace std;
int n,x;
struct MOVIE{
    int a,b,sum;
    void cal(){sum=a+b;}
}mov[200005];
long long min(long long x,long long y){return x<y?x:y;}
long long ans=0x7fffffffffffffff,minb[200005],sum[200005];
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>mov[i].a>>mov[i].b;
        mov[i].cal();
        minb[i]=0x7fffffffffffffff;
    }
    minb[1]=mov[1].b;
    sum[1]=mov[1].sum;
    for(int i=2;i<=n;i++){
        minb[i]=min(minb[i-1],mov[i].b);
        sum[i]=sum[i-1]+mov[i].sum;
    }
    for(int i=1;i<=min(x,n);i++){
        ans=min(ans,(x-i)*minb[i]+sum[i]);
    }
    cout<<ans;
}