#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::set<long long> s;
std::map<long long,int> m;
int cnt;
long long query(long long x){
    if(!m[x])m[x]=1;
    for(int i=m[x];i<=cnt+1;i++){
        if(s.find(x*(long long)i)==s.end())return x*(long long)i;
    }
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int q;
    cin>>q;
    while(q--){
        char opt;
        long long x;
        cin>>opt>>x;
        if(opt=='+')s.insert(x),cnt++;
        if(opt=='?')cout<<query(x)<<endl;
    }
    return 0;
}