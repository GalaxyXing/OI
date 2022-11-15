#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define int long long
int  dp[2005][2005],a[2005];

signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    for(int  i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        for(int  j=1;j<=std::min(i,m);j++){
            dp[i][j]=dp[i-1][j-1]+a[i]*j;
            if(i-1>=j)dp[i][j]=std::max(dp[i][j],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}