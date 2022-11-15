#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::basic_string<int> G[100005];
int n,m;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u]+=v;
        G[v]+=u;
    }
    for(int i=1;i<=n;i++){
        std::sort(G[i].begin(),G[i].end());
    }
    for(int i=1;i<=n;i++){
        cout<<G[i].size()<<" ";
        for(auto v:G[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}