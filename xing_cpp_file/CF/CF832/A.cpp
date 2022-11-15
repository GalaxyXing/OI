#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
long long sum1,sum2;
void solve(){
    int n;
    cin>>n;
    sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>0)sum1+=x;
        else sum2+=-x;
    }
    cout<<std::abs(sum1-sum2)<<endl;
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