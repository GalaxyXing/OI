#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int a,b,c;
    int ans=-1;
    cin>>a>>b>>c;
    if(a*b>0&&std::abs(a)<std::abs(b))ans=std::abs(a);
    else if(a*b>0&&std::abs(a)>std::abs(b)){
        if(b*c>0&&std::abs(c)<std::abs(b))ans=std::abs(a);
        else if(b*c<0)ans=2*std::abs(c)+std::abs(a);
    }else ans=std::abs(a);
    cout<<ans;
    return 0;
}