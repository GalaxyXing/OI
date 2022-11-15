#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::vector<int> V; 
int n,k;
int dp[105][10005];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int s;
        cin>>s;
        V.push_back(s);
    }
    int a=0;
    while(n){
        int i=V.back();
        V.pop_back();
        if(i==0)break;
        int cnt=n/i;
        n=n%i;
        int t=cnt/2;
        ans+=t*i;
        if(cnt%2==1&&a==0)ans+=i;
        a=(a+cnt)%2;
    }
    if(a==0)ans+=n;
    cout<<ans;
    return 0;
}