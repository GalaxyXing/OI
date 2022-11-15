#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int n,m;
std::basic_string<int> G[500005];
std::priority_queue<int,std::vector<int>,std::greater<int> > tsq;
int id[500005];
void topsort(){
	for(int i=1;i<=n;i++){
		if(id[i]==0){
			tsq.push(i);
		}
	}
}
	
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
		id[v]++;
	}
	topsort();
	
}
