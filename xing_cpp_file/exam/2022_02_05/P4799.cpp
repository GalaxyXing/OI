#include<cstdio>
struct EDGE{
    int to,next;
}e[200005];
int head[200005<<1],cntedge,val[200005];
void addedge(int u,int v){
    e[++cntedge].next=head[u];
    e[cntedge].to=v;
    head[u]=cntedge;
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",val+i);
    }
    
}