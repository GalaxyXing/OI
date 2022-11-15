#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int n;
int a[25];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
void dfs(int &ans,int now,int val,int gc){
    if(gc==1)ans=std::min(ans,val);
    else if(!now)return;
    else {
        dfs(ans,now-1,val,gc);
        dfs(ans,now-1,val+n-now+1,gcd(gc,gcd(a[now],now)));
        if(gcd(a[now],now)==now){
            ans=std::min(ans,val+(n-now+1)*2);
            return;
        }
    }
}
int dp[20][800];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int gc=a[1];
    int maxans=10000000;
    for(int i=2;i<=n;i++){
        gc=gcd(gc,a[i]);
    }
    dfs(maxans,n,0,gc);
    cout<<maxans<<endl;
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