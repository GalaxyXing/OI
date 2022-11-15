#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
void solve(){
    int n;
    cin>>n;
    cout<<(n+1)/2<<endl;
    if(n&1){
        if(n==1){
            cout<<"1 2"<<endl;
            return;
        }else{
            for(int i=1;i<=(n+1)/2;i++){
                cout<<i*3-1<<" "<<(i+(n-1)/2)*3<<endl;
            }
        }
    }else{
        for(int i=1;i<=n/2;i++){
            cout<<i*3-1<<" "<<(i+n/2)*3<<endl;
        }
    }
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