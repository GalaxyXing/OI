#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int p=998244353;
int qp(int x,int y){
    if(y==1)return x;
    long long tmp=(long long)qp(x,y>>1);
    tmp*=tmp;
    tmp%=p;
    return (y&1)?tmp*x%p:tmp;
}
int n;
std::basic_string<int> s;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s+=x;
    }
    
    return 0;
}