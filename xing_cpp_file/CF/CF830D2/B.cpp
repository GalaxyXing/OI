#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::bitset<100005> bit;
void solve(){
    int n;
    std::string s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)bit[i]=(s[i-1]-'0');
    int x=0,last=0,cnt=0;
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<(bit[i]^x)<<" "<<(bit[i-1]^last)<<endl;
        if((bit[i]^x)<(bit[i-1]^last)){
            x^=1,
            cnt++;
        }
        last=x;
    }
    cout<<cnt<<endl;
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