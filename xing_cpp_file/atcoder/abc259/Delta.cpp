#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#define int long long
using namespace std;
struct EDGE{
    int next,to;
}e[3001*3000*2];
struct CIRCLE{
    int x,y,r;
}circle[3005];
int head[3005],cntedge;
void addedge(int u,int v){
    e[++cntedge].to=v;
    e[cntedge].next=head[u];
    head[u]=cntedge;
}
vector<int>st,fn;
int n;
int stx,sty,fnx,fny;
bool flag[3005];
int dist(int x1,int x2,int y1,int y2){
    return((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int dis(int x,int y){
    return dist(circle[x].x,circle[y].x,circle[x].y,circle[y].y);
}

queue<int> q;
bool bfs(){
    for(int i=0;i<st.size();i++){
    //    cout<<" st "<<st[i]<<endl;
        q.push(st[i]);
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(flag[t]==1)continue;
        flag[t]=1;
        for(int i=head[t];i;i=e[i].next){
            if(flag[e[i].to]==1)continue;
            q.push(e[i].to);
        }
    }
    for(int i=0;i<fn.size();i++){
    //    cout<<" fn "<<fn[i]<<endl;
        if(flag[fn[i]]==1)return true;
    }
    return false;
}
signed main(){
    cin>>n;
    cin>>stx>>sty>>fnx>>fny;
    for(int i=1;i<=n;i++){
        cin>>circle[i].x>>circle[i].y>>circle[i].r;
        if(dist(circle[i].x,stx,circle[i].y,sty)==circle[i].r*circle[i].r)st.push_back(i);
        if(dist(circle[i].x,fnx,circle[i].y,fny)==circle[i].r*circle[i].r)fn.push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            else if(dis(i,j)<=(circle[i].r+circle[j].r)*(circle[i].r+circle[j].r)&&dis(i,j)>=((circle[i].r-circle[j].r)*(circle[i].r-circle[j].r))){
                addedge(i,j);
                addedge(j,i);
            }
        }
    }
    if(bfs())cout<<"Yes";
    else cout<<"No";
}