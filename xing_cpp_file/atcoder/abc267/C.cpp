#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define int long long
int dp[200050],n,m,a[200005],sum[200005];
signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        dp[1]+=a[i]*i;
    }
    int ans=dp[1];
    for(int i=2;i+m-1<=n;i++){
        // cout<<dp[i];
        dp[i]=dp[i-1]-(sum[i-1+m-1]-sum[i-2])+a[i+m-1]*m;
        ans=std::max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}