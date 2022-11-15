#include<cstdio>
#include<queue>
#include<map>
using namespace std;
inline int read(){
    int re=0;
    char t=getchar();
    while(t<'0'||t>'9')t=getchar();
    while(t>='0'&&t<='9')re=(re<<3)+(re<<1)+(t^48),t=getchar();
    return re;
}
bool mapp[60][60],flag[60][60][4];
int to_dir(char x){
    if(x=='N')return 0;
    else if(x=='W')return 1;
    else if(x=='S')return 2;
    else if(x=='E')return 3;
    return 0;
}
char to_cdir(int x){
    if(x==0)return 'N';
    else if(x==1)return 'W';
    else if(x==2)return 'S';
    else if(x==3)return 'E';
    return 0;
}
int n,m;
struct NODE{
    int time,x,y,dir;
    bool operator<(const NODE &a)const{return a.time>time;}
    bool operator!=(const NODE &a)const{return a.time!=time||a.dir!=dir||a.x!=x||a.y!=y;}
};
struct DEB{
    NODE fa;
    int fuc;
};
queue<NODE> q;
map<NODE,DEB> fa;
NODE st,fn;
bool checkm(NODE x){
    if(x.x<1||x.y<1)return false;
    if(x.x>=n||x.y>=m)return false;
    if(mapp[x.x][x.y])return false;
    if(mapp[x.x+1][x.y])return false;
    if(mapp[x.x][x.y+1])return false;
    if(mapp[x.x+1][x.y+1])return false;
    //if(flag[x.x][x.y][x.dir])return false;
    return true;
}
bool checkf(NODE x){
    if(flag[x.x][x.y][x.dir])return false;
    else return true;
}
NODE go(NODE x,int y){
    if(x.dir==0)x.x-=y;
    else if(x.dir==1)x.y-=y;
    else if(x.dir==2)x.x+=y;
    else if(x.dir==3)x.y+=y;
    x.time++;
    return x;
}
NODE tl(NODE x){
    x.dir=(x.dir+1)%4;
    x.time++;
    return x;
}
NODE tr(NODE x){
    x.dir=(x.dir+3)%4;
    x.time++;
    return x;
}
void dfs(NODE x){
    if(x!=st)dfs(fa[x].fa);
    printf("fuc %d x %d y %d dir %c time %d\n",fa[x].fuc,x.x,x.y,to_cdir(x.dir),x.time);
}
int BFS(){
    st.time=0;
    flag[st.x][st.y][st.dir]=true;
    q.push(st);
    while(!q.empty()){
        NODE cur=q.front();
        q.pop();
     //   printf("x %d y %d dir %c time %d\n",cur.x,cur.y,to_cdir(cur.dir),cur.time);
        if(cur.x==fn.x&&cur.y==fn.y){
        //    printf("ans:");
        //    dfs(cur);
            return cur.time;
        }
        NODE nxt;
        for(int i=1;i<=3;i++){
            nxt=go(cur,i);
            if(checkm(nxt)&&checkf(nxt)){
                q.push(nxt);
                fa[nxt].fa=cur;
                fa[nxt].fuc=i;
                flag[nxt.x][nxt.y][nxt.dir]=1;
            }else if(!checkm(nxt)) break;
        }
        nxt=tl(cur);        
        if(checkm(nxt)&&checkf(nxt)){
            q.push(nxt);
            flag[nxt.x][nxt.y][nxt.dir]=1;
            fa[nxt].fa=cur;fa[nxt].fuc=4;
         //   printf("fuc %d x %d y %d dir %c time %d\n",
          //      fa[nxt].fuc,nxt.x,nxt.y,to_cdir(nxt.dir),nxt.time);        
        }
        nxt=tr(cur);        
        if(checkm(nxt)&&checkf(nxt)){
            q.push(nxt);
            flag[nxt.x][nxt.y][nxt.dir]=1;
            fa[nxt].fa=cur;fa[nxt].fuc=5; 
         //   printf("fuc %d x %d y %d dir %c time %d\n",
          //      fa[nxt].fuc,nxt.x,nxt.y,to_cdir(nxt.dir),nxt.time);       
        }
        
    }
    return -1;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mapp[i][j]=(read()==1);
        }
    }
    st.x=read(),st.y=read();
    fn.x=read(),fn.y=read();
    st.dir=to_dir(getchar());
    printf("%d",BFS());
    return 0;
}