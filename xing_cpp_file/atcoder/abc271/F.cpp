#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int mp[25][25];
std::map<int,unsigned long long> dp[25][25];
int dx[]={-1,0},dy[]={0,-1};
unsigned long long dfs(int x,int y,int s){
    if(dp[x][y][s]!=0)return dp[x][y][s];
    for(int i=0;i<2;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0){
            dp[x][y][s]+=dfs(nx,ny,s^mp[x][y]);
        }
    }
    return dp[x][y][s];
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    dp[1][1][mp[1][1]]=1;
    cout<<dfs(n,n,0)<<endl;    
    return 0;
}