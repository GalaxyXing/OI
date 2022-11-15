#include<iostream>
#define int long long
using namespace std;
int n;
int sq[15][15],maxx;
int max(int x,int y){return x>y?x:y;}
const int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int solve(int i,int j,int x,int y){
    int re=0;
    int nx=i,ny=j;
    for(int i=1;i<=n;i++){
        re=re*10+sq[nx][ny];
     //   cout<<re<<' '<<sq[nx][ny]<<' '<<nx<<' '<<ny<<endl;
        nx+=x,ny+=y;
        if(nx>n)nx=1;
        if(ny>n)ny=1;
        if(nx==0)nx=n;
        if(ny==0)ny=n;
    }
    return re;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t=getchar();
            if(t=='\n')t=getchar();
            sq[i][j]=t-'0';
        //    cout<<i<<' '<<j<<' '<<sq[i][j]<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<8;k++){
                maxx=max(maxx,solve(i,j,dx[k],dy[k]));
            }
        }
    }
    cout<<maxx;
    return 0;
}