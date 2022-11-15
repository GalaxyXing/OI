#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a[100005];
void solve(){
    int n;
    bool flag=false;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int st=a[1]-1;
    for(int i=2;i<=n;i++){
        if(a[i]<=st){
            flag=true;
            break;
        }
    }
    if(!flag)cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
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