#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int n,a[2005];
int check(int x){
    int cnt=0,sum=0,re=0;
    for(int i=1;i<=n;i++){
    //    cout<<"i "<<i<<endl;
        if(cnt+(a[i]-a[i-1])>x)return -1;
        else if(cnt+(a[i]-a[i-1])==x){
            re=std::max(re,sum+1),sum=cnt=0;
        }else cnt+=a[i]-a[i-1],sum++;
    }
    if(cnt==x)re=std::max(sum,re);
    else if(cnt<x&&cnt>0)return -1;
    return re;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    int ans=n;
    for(int i=1;i<=n;i++){
     //   cout<<"QAQ"<<" "<<i<<endl;
        int c=check(a[i]);
        ans=std::min(ans,c==-1?ans:c);
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}