#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct Ans{
    bool b;
    char c;
}dp[105][10005];
struct Card{
    int a,b;
}card[105];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n,S;
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        cin>>card[i].a>>card[i].b;
    }
    dp[0][0].b=1;
    for(int i=1;i<=n;i++){
        for(int j=card[i].a;j<=S;j++){
            if(dp[i-1][j-card[i].a].b)dp[i][j].b=1,dp[i][j].c='H';
        }
        for(int j=card[i].b;j<=S;j++){
            if(dp[i-1][j-card[i].b].b)dp[i][j].b=1,dp[i][j].c='T';
        }
    }
    std::string ans;
    if(dp[n][S].b){
        cout<<"Yes"<<endl;
        for(int i=n;i>=1;i--){
            ans+=dp[i][S].c;
            S-=(dp[i][S].c=='H'?card[i].a:card[i].b);
        }
        std::reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }else {
        cout<<"No"<<endl;
    }
    return 0;
}