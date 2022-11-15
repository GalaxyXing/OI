#include<cstdio>
#include<unordered_map>
#include<queue>
typedef long long ll;
ll st,fn=111111111111;
std::queue<ll> lock;
std::unordered_map<ll,short> vis,step;
std::unordered_map<ll,std::deque<short> > path;
int a[15][5],map[13];
void init(){
    for(int i=1;i<=12;i++){
        int tmp;
        scanf("%d",&tmp);
        st=st*10+tmp;
        for(int j=1;j<=4;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void bfs(){
    lock.push(st),lock.push(fn);
    vis[st]=1,vis[fn]=2;
    step[st]=0,step[fn]=1;
    path[st].push_back(0);
    path[fn].push_back(0);
    while (!lock.empty()){
        ll cur=lock.front();
        lock.pop();
        {
            ll tmp=cur;
            for(int i=12;i>=1;i--){
                map[i]=tmp%10;
                tmp/=10;
             }
        }
        for(int i=1;i<=12;i++){
            if(vis[cur]==1){
                map[a[i][map[i]]]++;
                if(map[a[i][map[i]]]==5)map[a[i][map[i]]]=1;
                map[i]++;
               if(map[i]==5)map[i]=1;
            }else if(vis[cur]==2){
                map[i]--;
                if(map[i]==0)map[i]=4;
                map[a[i][map[i]]]--;
                if(map[a[i][map[i]]]==0)map[a[i][map[i]]]=4;
            }            
            ll nxmap=0;
            for(int j=1;j<=12;j++){
                nxmap=nxmap*10+map[j];
            }
            if(vis.find(nxmap)==vis.end()){
                vis[nxmap]=vis[cur];
                step[nxmap]=step[cur]+1;
                path[nxmap]=path[cur];
                path[nxmap].push_back(i);
                lock.push(nxmap);
            }else if(vis[nxmap]+vis[cur]==3){
                printf("%d\n",step[nxmap]+step[cur]);
                if(vis[nxmap]==1){
                    std::deque<short> tmp1=path[nxmap],tmp2=path[cur];
                    tmp1.pop_front();
                    while(!tmp1.empty()){
                        printf("%d ",tmp1.front());
                        tmp1.pop_front();
                    }
                    printf("%d ",i);
                    tmp2.pop_front();
                    while(!tmp2.empty()){
                        printf("%d ",tmp2.back());
                        tmp2.pop_back();
                    }
                }else if(vis[cur]==1){
                    std::deque<short> tmp2=path[nxmap],tmp1=path[cur];
                    tmp1.pop_front();
                    while(!tmp1.empty()){
                        printf("%d ",tmp1.front());
                        tmp1.pop_front();
                    }
                    printf("%d ",i);
                    tmp2.pop_front();
                    while(!tmp2.empty()){
                        printf("%d ",tmp2.back());
                        tmp2.pop_back();
                    }
                }
                return;
            }
            if(vis[cur]==2){
                map[a[i][map[i]]]++;
                if(map[a[i][map[i]]]==5)map[a[i][map[i]]]=1;
                map[i]++;
               if(map[i]==5)map[i]=1;
            }else if(vis[cur]==1){
                map[i]--;
                if(map[i]==0)map[i]=4;
                map[a[i][map[i]]]--;
                if(map[a[i][map[i]]]==0)map[a[i][map[i]]]=4;
            }
        }
        path.erase(cur);
    }
    
}
int main(){
    init();
    bfs();
    return 0;
}