#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
void solve(){
    int n;
    cin>>n;
    if(n==3){
        cout<<"-1";
    }else if(n==5){
        cout<<"5 4 1 2 3";
    }else if(n%2==0){
        for(int i=1;i<=n/2;i++){
            cout<<i*2<<" "<<i*2-1<<" ";
        }
    }else{
        for(int i=n;i>=n-2;i--)cout<<i<<" ";
        for(int i=1;i<n-2;i++)cout<<i<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}