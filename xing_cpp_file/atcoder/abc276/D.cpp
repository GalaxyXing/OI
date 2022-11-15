#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::basic_string<int> a;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;a+=x;
    }
    int agcd=a.front();
    for(auto i:a){
        agcd=std::__gcd(agcd,i);
    }
    for(auto &i:a){
        i/=agcd;
    }
    int ans=0;
    for(auto i:a){
        while(!(i&1)){
            i>>=1;
            ans++;
        }
        while(!(i%3)){
            i/=3;
            ans++;
        }
        if(i!=1){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}