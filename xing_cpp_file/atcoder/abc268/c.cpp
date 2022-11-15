#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::set<long long> q;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    long long n;
    cin>>n;
    q.insert(0);
    for(long long i=n;i;i=(i-1)&n){
        q.insert(i);
    }
    for(auto i:q){
        cout<<i<<endl;
    }
    return 0;
}