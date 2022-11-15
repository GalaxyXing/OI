#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int f(int x){
    return (x==0)?1:x*f(x-1);
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int x;
    cin>>x;
    cout<<f(x);
    return 0;
}