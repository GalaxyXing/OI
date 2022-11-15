#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
bool dp[200005],flag[200005];
int a[200005];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        // cout<<"i "<<i<<endl;
        // for(int j=1;j<=n;j++){
        //     cout<<dp[j]<<" ";
        // }cout<<endl;
        // cout<<"i+a "<<(i+a[i]<=n)<<endl;
        if(a[i]<i)dp[i]=dp[i]||dp[i-a[i]-1];
        if(i+a[i]<=n)dp[i+a[i]]=dp[i-1]||dp[i+a[i]];
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<(dp[n]?"YES":"NO")<<endl;
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