#include<cstdio>
struct SC{
    int suan,ku;
}sc[15];
unsigned suan=1,ku,ans=0x7fffffff;
int n,path[15];
inline unsigned absmin(unsigned x,unsigned y){
    return (x>y)?x-y:y-x;
}
inline bool checkpath(){
    for(int i=1;i<=n;i++){
        if(path[i]!=0)return 1;
    }
    return 0;
}
inline unsigned min(unsigned x,unsigned y){
    return (x<y)?x:y;
}
void DFS(int depth){
    if(depth>n){
        if(checkpath()){
           // printf("%u %u %u\n",suan,ku,absmin(suan,ku));
            ans=min(ans,absmin(suan,ku));
        }
        return;
    }
    path[depth]=depth;
    suan*=sc[depth].suan;
    ku+=sc[depth].ku;
    DFS(depth+1);
    path[depth]=0;
    suan/=sc[depth].suan;
    ku-=sc[depth].ku;
    DFS(depth+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&sc[i].suan,&sc[i].ku);
    }
    sc[0].suan=1,sc[0].ku=0;
    DFS(1);
    printf("%u",ans);
    return 0;
}