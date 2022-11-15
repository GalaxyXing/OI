#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct Edge{
    int v,w,id;
    Edge(int a,int b,int c){v=a,w=b,id=c;}
};
std::vector<Edge> G[200005];
std::vector<int> v[200005];
struct Node{
    int x,dis,lid;
    Node(int a=0,int b=0){x=a,dis=b;}
    const bool operator<(const Node &x){return dis>x.dis;}
};
std::priority_queue<Node> q;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back(Edge(b,c,i));
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    
    return 0;
}