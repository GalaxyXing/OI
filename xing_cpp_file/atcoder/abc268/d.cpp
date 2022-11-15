#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int dx[]={-1,-1,0,0,1,1},dy[]={-1,0,-1,1,0,1};
struct Pos{
    int x,y;
    Pos(int a=0,int b=0){x=a,y=b;}
    Pos map(){
        return Pos(x+1000,y+1000);
    }
    Pos remap(){
        return Pos(x-1000,y-1000);
    }
}cell[1005];
bool ok[2055][2055];
bool black[2055][2055];
int ans;
std::queue<Pos> q;
void bfs(Pos p){
    q.push(p);
    black[p.x][p.y]=true;
    while(!q.empty()){
        Pos tmp=q.front();
        q.pop();
        for(int i=0;i<6;i++){
            Pos nt(tmp.x+dx[i],tmp.y+dy[i]);
            if(nt.x>=0&&nt.x<=2000&&nt.y>=0&&nt.x<=2000){
                if(ok[nt.x][nt.y]&&!black[nt.x][nt.y])q.push(nt),black[nt.x][nt.y]=true;
            }
        }
    }
    return ;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cell[i].x>>cell[i].y;
        cell[i]=cell[i].map();
        ok[cell[i].x][cell[i].y]=true;
    }
    for(int i=1;i<=n;i++){
        if(!black[cell[i].x][cell[i].y]){
            bfs(cell[i]);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}