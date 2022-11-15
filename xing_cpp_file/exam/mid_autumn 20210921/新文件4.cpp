#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=1e6+10;
struct edge{
	int to,to_check;
}que[MAX];
int n,cnt,u[MAX];
bool vis[MAX];
bool to[MAX];
int visi[MAX];
int ans;
int check[MAX][2];
int dfs(int x,int check,i){
	if(vis[x]){
		if(check+1==visi[x]){
			
		}
		else return 0;
	}
	if(check){
		vis[u[x]]=true;
		visi[u[x]]=que[u[x]].to_check+1;
		check[que[u[x]].to][que[u[x]].to_check]=dfs(que[u[x]].to,que[u[x]].to_check,i+1);
		vis[u[x]]=false;
		visi[u[x]]=0;
	}else{
		vis[u[x]]=true;
		visi[u[x]]=(!que[u[x]].to_check)+1;
		dfs(que[u[x]].to,!que[u[x]].to_check);
		vis[u[x]]=false;
		visi[u[x]]=0;
	}
}

void add(int e,int v,int w){
	cnt++;
	que[cnt].to=v;
	que[cnt].to_check=w;
	to[v]=true;
	u[e]=cnt;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp1,tmp2;
		cin>>tmp1>>tmp2;
		add(i,tmp1,tmp2);
	}
	for(int i=1;i<=n;i++){
		if(!to[i]){
			dfs(i,1,1);
			dfs(i,0,1);
		}
	}
	
}