#pragma g++ optimize(2)
#include<cstdio>
#include<queue>
#include<map>
const short dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int map[4][4],bg,fn=123804765;
struct NODE{
    int map,step;
};
std::map<int,int> m,step;
std::queue<NODE> q;
inline void swap(int &x,int &y){
    int tmp=x;
    x=y,y=tmp;
    return;
}
void bfs(){
    q.push({bg,0});
    q.push({fn,0});
    m[bg]=1,m[fn]=2;
    step[bg]=0,step[fn]=1;
    while(!q.empty()){
        NODE tmp=q.front();
        q.pop();
        int cx,cy;
        int cur=tmp.map;
        for(int i=3;i>=1;i--){
            for(int j=3;j>=1;j--){
                map[i][j]=tmp.map%10;
                tmp.map/=10;
                if(map[i][j]==0)cx=i,cy=j;
            }
        }
        for(int i=0;i<4;i++){
            int nx=cx+dx[i],ny=cy+dy[i];
            if(nx<=3&&ny<=3&&nx>=1&&ny>=1){
                swap(map[cx][cy],map[nx][ny]);
                int nxmap=0;
                for(int i=1;i<=3;i++){
                    for(int j=1;j<=3;j++){
                        nxmap=nxmap*10+map[i][j];
                    }
                }
                if(m.find(nxmap)==m.end()){
                    m[nxmap]=m[cur],step[nxmap]=step[cur]+1;
                    q.push({nxmap,tmp.step+1});
                }else if(m[nxmap]+m[cur]==3){
                    int ans=step[nxmap]+step[cur];
                    printf("%d",ans);
                    return;
                }else if(m[nxmap]==m[cur]){
                    swap(map[cx][cy],map[nx][ny]);
                    continue;
                }
                swap(map[cx][cy],map[nx][ny]);
            }
        }
    }
}
int main(){
    scanf("%d",&bg);
    if(bg==fn)printf("0");
    else bfs();
    return 0;
}