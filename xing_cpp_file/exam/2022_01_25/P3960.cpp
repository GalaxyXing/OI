#include<cstdio>
int fz[10000005];
int left,n,m,q;
inline int pos(int x,int y){
    return (x-1)*m+y;
}
void xzkq(int x,int y){//向左看齐
    for(int i=y+1;i<=m;i++){
        fz[pos(x,i-1)]=fz[pos(x,i)];
    }fz[pos(x,m)]=0;
}
void xqkq(int x){//向前看齐
    for(int i=x+1;i<=n;i++){
        fz[pos(i-1,m)]=fz[pos(i,m)];
    }fz[pos(n,m)]=left;
}
void pre(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    fz[pos(i,j)]=pos(i,j);
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    pre();
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        left=fz[pos(x,y)];
        xzkq(x,y);
        xqkq(x);
        printf("%d\n",left);
    }
    return 0;
}