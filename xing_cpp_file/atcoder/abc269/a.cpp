#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a[8];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int a,b;
    cin>>a>>b;
    cout<<(a|b);
    return 0;
}