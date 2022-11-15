#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#define MAXA 200050
using namespace std;
struct EDGE{
    int from,to,val;
    bool operator<(const EDGE &x)const{
        return val<x.val;
    }
}e[MAXA<<1];
struct NODE{
    int a,fa,origin;
    vector<int> son;
}nod[MAXA];
int cntedge,n,m,q;
queue<int> cut;
void addedge(int u,int v){
    e[++cntedge].from=u;
    e[cntedge].to=v;
    e[cntedge].val=-(q+1);
    e[++cntedge].from=v;
    e[cntedge].to=u;
    e[cntedge].val=-(q+1);
}
void deedge(int x){
    cut.push(2*x);
    cut.push(2*x-1);
}
void gc(int t){
    while(!cut.empty()){
        e[cut.front()].val=(-t);
        cut.pop();
    }
}
inline int read(){
    int re=0,di=1;
    char t=getchar();
    while(t>'9'||t<'0'){
        if(t=='-')di=-1;
        t=getchar();
    }
    while(t<='9'&&t>='0')re=(re<<3)+(re<<1)+t-'0',t=getchar();
    return re*di;
}
inline string reads(){
    string re="";
    char t=getchar();
    while(t>'Z'||t<'A')t=getchar();
    while(t<='Z'&&t>='A')re+=t,t=getchar();
    return re;
}
void Kruskal(int from){
    sort(e+1,e+cntedge+1);
    for(int i=1;i<=cntedge;i++){}
}
void Solve();
int main(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        addedge(u,v);
    }
    for(int i=1;i<=q;i++){
        string tmp=reads();
        if(tmp=="DELETE"){
            int t=read();
            deedge(t);
        }else if(tmp=="GC"){
            gc(i);
        }
    }
    Kruskal(1);
    for(int i=1;i<=n;i++){
        nod[i].a=read();
        nod[i].fa=nod[i].origin=i;

    }
    Solve();
}