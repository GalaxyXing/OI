//≥Ê ≥À„90fen...
#include<cstdio>
#include<cstdlib>
char word[4][30];
bool flag_unknown[30]={},flag_int[30]={},flag_up[30];
int known[30],n;
void DFS(int);
void dfs(int ,int);
inline int char_to_int(char x){return x-'A'+1;}
bool check(int x){
    int add[4]={};
    for(int i=1;i<=3;i++)add[i]=known[char_to_int(word[i][x])];
    add[0]=(add[1]+add[2]+flag_up[x+1])%n;
    if(add[0]!=add[3])return false;
    flag_up[x]=(add[1]+add[2]+flag_up[x+1])/n;
    return true;
}
void dfs(int x,int y){
    if(x>3){
        if(check(y))DFS(y-1);        
        return ;
    }
    int cti=char_to_int(word[x][y]);
    if(flag_unknown[cti]==0){
        for(int i=n-1;i>=0;i--){
            if(flag_int[i]==0){
                flag_int[i]=1,flag_unknown[cti]=1,known[cti]=i;
                dfs(x+1,y);
                flag_int[i]=0,flag_unknown[cti]=0,known[cti]=0;
            }    
        }
    }else dfs(x+1,y);
}
void output(){
    for(int i=1;i<=n;i++)printf("%d ",known[i]);
    exit(0);
}
void DFS(int x){
    if(x==0)output();
    else dfs(1,x);    
}
int main(){
    scanf("%d",&n),getchar();
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            scanf("\n%c",&word[i][j]);
        }
    }
    DFS(n);
    return 0;
}