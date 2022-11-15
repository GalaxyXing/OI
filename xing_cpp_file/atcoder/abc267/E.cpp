#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::vector<int> G[200005];
int a[200005],s[200005];
std::priority_queue <int> pq;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(int  v:G[i]){
            s[i]+=a[v];
        }
        pq.push(s[i]);
    }
    while(!pq.empty()){
        
    }
    return 0;
}