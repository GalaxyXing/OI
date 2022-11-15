#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a,b,c,d;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>a>>b>>c>>d;
    cout<<(a+b)*(c-d)<<endl<<"Takahashi";
    return 0;
}