#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int edge[105][105];
int ans;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[u][v]=1;
        edge[v][u]=1;
    }
    for(int i=2;i<=n-1;i++){
        for(int j=1;j<i;j++){
            for(int k=i+1;k<=n;k++){
                ans+=edge[i][j]*edge[i][k]*edge[j][k];
            }
        }
    }
    cout<<ans;
    return 0;
}