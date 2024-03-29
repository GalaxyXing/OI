#include<cstdio>
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1}; 
int N,M, p[1005][1005],minp=1005,maxp;
bool vis[1005][1005];
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
struct PT{int x,y;};
struct QUEUE{
    int begin,end;
    PT q[1000005];
    void push(PT x){q[++end]=x;}
    void pop(){begin++;}
    int size(){return end-begin;}
    bool empty(){return end==begin;}
    void clear(){begin=end=0;}
    PT front(){return q[begin+1];}
}q;
bool check(int x){
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)vis[i][j]=0;
    q.clear(),q.push({1,1}),vis[1][1]=1;
    while(!q.empty()){
        PT cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(nx>0&&nx<=N&&ny>0&&ny<=M&&vis[nx][ny]==0){
                if(p[nx][ny]>x)continue;
                else {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    if(nx==N)return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) 
    scanf("%d",&p[i][j]),minp=min(minp,p[i][j]>0?p[i][j]:1005),maxp=max(maxp,p[i][j]);
    int l=minp-1,r=maxp+1,mid;
    while(r-l>1)mid=(r+l)>>1,check(mid)?r=mid:l=mid;
    printf("%d",r);
    return 0;
}