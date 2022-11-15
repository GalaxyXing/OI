#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
int n,a[105],dp[105][105][105][105],ans;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j][0][0]=1;
            for(int k=1;k<=std::min(i,j);k++){
                for(int l=0;l<i;l++){
                    int p=a[j]%i,t;
                    if(p>l){
                        t=i+l-p;
                    }else t=l-p;
                    dp[i][j][k][l]=dp[i][j-1][k][l]+dp[i][j-1][k-1][t];
                    dp[i][j][k][l]%=998244353;
                }
            }
        }
        ans+=dp[i][n][i][0];
        ans%=998244353;
    }
    cout<<ans;
}