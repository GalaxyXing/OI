//记得打印核酸报告
#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
int n,a[200005],d[200005],g;
int gcd(int x,int y){
    return (y==0)?x:gcd(y,x%y);
}
signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];    
    std::sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)d[i]=a[i]-a[i-1];
    g=std::__gcd(d[2],d[3]);
    for(int i=2;i<=n;i++){
        g=std::__gcd(g,d[i]);
    }
    cout<<(g==1?2:1);
    return 0;
}
