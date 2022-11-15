#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::vector<int> G[200005];
std::vector<int> P;
int n,x,y;
void dfs(int fa,int pos){
    P.push_back(pos);
    if(pos==y){
        for(auto i:P){
            cout<<i<<" ";
        }
        exit(0);
    }else{
        for(auto v:G[pos]){
            if(v==fa)continue;
            dfs(pos,v);
        }
    }
    P.pop_back();
}
int main(){ 
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>x>>y;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0,x);
    return 0;
}