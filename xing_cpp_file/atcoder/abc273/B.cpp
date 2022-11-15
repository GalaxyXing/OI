#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
void abt(int &x,int y){
    int tmp=x/y;
    int mod=(x/(y/10))%10;
    if(mod>=5)x=(tmp+1)*y;
    else x=tmp*y;
    return;
}
signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int x,k;
    cin>>x>>k;
    int base=1;
    for(int i=1;i<=k;i++){
        base*=10;
        abt(x,base);
    }
    cout<<x<<endl;
    return 0;
}