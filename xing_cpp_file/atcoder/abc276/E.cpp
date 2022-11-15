#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m;
bool vis[1005005];
int val[1005005];
char map[1005005];
int cnt;
struct Pos{
    int x,y;
    Pos(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator==(const Pos &x)const{
        return this->x==x.x&&this->y==x.y;
    }
    int toi(){
        return (x-1)*m+y;
    }
}st;
struct Node{
    Pos p;
    int d;
    Node(Pos _p=Pos(0,0),int _d=0):p(_p),d(_d){}
};
bool check(Pos x){
    if(x.x<1||x.x>n)return false;
    else if(x.y<1||x.y>m)return false;
    else if(vis[x.toi()])return false;
    else if(map[x.toi()]=='#')return false;
    else return true;
}
bool ck(Pos x){
    if(x.x<1||x.x>n)return false;
    else if(x.y<1||x.y>m)return false;
    else if(map[x.toi()]=='#')return false;
    return true;
}
void dfs(Pos p,int v){
    vis[p.toi()]=1;
    val[p.toi()]=v;
    for(int i=0;i<4;i++){
        Pos nxt=Pos(p.x+dx[i],p.y+dy[i]);
        if(check(nxt)){
            dfs(nxt,v);
        }
    }
}
bool judge(){
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            Pos x=Pos(st.x+dx[i],st.y+dy[i]),y=Pos(st.x+dx[j],st.y+dy[j]);
            if(ck(x)&&ck(y)){
                if(val[x.toi()]==val[y.toi()])return true;
            }
        }
    }
    return false;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[Pos(i,j).toi()];
            if(map[Pos(i,j).toi()]=='S')st=Pos(i,j),map[Pos(i,j).toi()]='#';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(Pos(i,j))){
                dfs(Pos(i,j),++cnt);
            }
        }
    }
    if(judge()){
        cout<<"Yes";
    }else cout<<"No";
    return 0;
}