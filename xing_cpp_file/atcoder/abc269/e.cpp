#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define int long long
int last,dec;
std::priority_queue<int> q;
int n,k;
std::vector<int> V;
signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        V.push_back(x);
        if(x)q.push(-x);
    }
    while(k){
        int size=q.size();
        if(k<size)break;
        int t=-q.top();
        if(t==last){
            q.pop();
            continue;
        }
        if((t-last)*size>k)dec+=k/size,k%=size;
        else dec=t,k-=(t-last)*size,q.pop();
        last=t;
    }
    for(int i=0;i<n;i++){
        V[i]=std::max(0ll,V[i]-dec);
    }
    for(int i=0;i<n&&k;i++){
        if(V[i])V[i]--,k--;
    }
    for(auto i:V)cout<<i<<" ";
    return 0;
}