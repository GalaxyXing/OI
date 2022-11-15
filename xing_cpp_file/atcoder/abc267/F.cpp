#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::vector<int> G [200005];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int q;
    cin>>n;
    while(q--){
        int s,k;
        cin>>s>>k;
        dfs(s,k);
    }
    return 0;
}