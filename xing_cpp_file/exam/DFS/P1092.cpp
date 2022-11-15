//≥Ê ≥À„±©¡¶
#include<cstdio>
#include<cstdlib>
char add[4][50];
int choice[50];
bool flag[50];
int n;
inline int char_to_int(char x){return x-'A'+1;}
bool check(){
    int iadd[4][50];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            iadd[i][j]=choice[char_to_int(add[i][j])];
        }
    }
    int jw=0;
    for(int i=n;i>=1;i--){
        iadd[0][i]=(jw+iadd[1][i]+iadd[2][i])%n;
        jw=(jw+iadd[1][i]+iadd[2][i])/n;
        if(iadd[0][i]!=iadd[3][i])return false;
    }
    return true;
}
void QPL(int x){
    if(x>n){
        if(check()){
            for(int i=1;i<=n;i++)printf("%d ",choice[i]);
            exit(0);
        }
        return ;
    } 
    for(int i=0;i<n;i++){
        if(flag[i]==1)continue;
        choice[x]=i;
        flag[i]=1;
        QPL(x+1);
        flag[i]=0;
    }
}
int main(){
    scanf("%d",&n),getchar();
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            scanf("\n%c",&add[i][j]);
        }
    }
    QPL(1);
    return 0;
}