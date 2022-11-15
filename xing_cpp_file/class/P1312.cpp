#include<cstdio>
#include<cstdlib>
int n;
int map[10][10][20];//map[a][b][9]��a�β����󣬵�b�л�ľ�ĸ߶�,a=0ʱΪ��ʼͼ����δ��������.
struct PATH{        //ע�⣡�����ʱx��yӦ�ֱ��1
    int x,y,drt;
}path[10];          //·��
bool checkall(int);//��������������ʱ��check
void Pre(int);//��ԭ����
void change(int,int,int,int);//����
void bingo(int);//������
void DFS(int);//������������
void down(int ,int);//����������׹��;
bool checkall(int f){
    for(int i=1;i<=5;i++){
        if(map[f][i][1]!=0)return false;
    }
    return true;
}
void Pre(int depth){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
            map[depth][i][j]=0;
            map[depth][i][j]=map[depth-1][i][j];
        }
    }
}
void down(int depth,int x){
    int cnt=0;
    map[depth][x][9]=0;
    for(int i=1;i<=7;i++){
        if(map[depth][x][i]==0)cnt++;
        else{
            map[depth][x][i-cnt]=map[depth][x][i];
            if(cnt!=0)map[depth][x][i]=0;
            map[depth][x][9]++;
        }
    } 
}
void change(int depth,int x,int y,int direct){
    int tmp=map[depth][x+direct][y];
    map[depth][x+direct][y]=map[depth][x][y];
    map[depth][x][y]=tmp;
    down(depth,x);
    down(depth,x+direct);
}
void bingo(int depth){
    bool flag=0;
    bool Bingo[10][10]={};
    for(int i=1;i<=5;i++){
        for(int j=1;j<=map[depth][i][9];j++){
            int tmp=map[depth][i][j];
            if(i>=2&&i<=4&&map[depth][i-1][j]==tmp&&map[depth][i+1][j]==tmp)
                flag=Bingo[i-1][j]=Bingo[i][j]=Bingo[i+1][j]=1;
            if(j>=2&&j<map[depth][i][9]&&map[depth][i][j-1]==tmp&&map[depth][i][j+1]==tmp)
                flag=Bingo[i][j+1]=Bingo[i][j]=Bingo[i][j-1]=1;
        }
    }
    if(!flag)return;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=map[depth][i][9];j++){
            if(Bingo[i][j]==1)map[depth][i][j]=0;
        }
        down(depth,i);
    }
    bingo(depth);//bingo��϶����п���Ҫ����bingo
}
void DFS(int depth){
    if(depth>n){
        if(checkall(n)){
            for(int i=1;i<=n;i++)
                printf("%d %d %d\n",path[i].x-1,path[i].y-1,path[i].drt);
            exit(0);
        }
        return;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=map[depth-1][i][9];j++){
            if(map[depth-1][i-1][j]==0&&i>1){//�������û�����Ż��������Ѿ�����ǰ�Ļ�����
                Pre(depth);
                change(depth,i,j,-1);
                bingo(depth);     
                path[depth]={i,j,-1};
                DFS(depth+1);
                
            }
            if(i<5){
                Pre(depth);
                change(depth,i,j,1);//���Ҷ��û�
                bingo(depth);
                path[depth]={i,j,1};
                DFS(depth+1);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=5;i++){
        int tmp,cnt=0;
        scanf("%d",&tmp);
        while(tmp){
            map[0][i][++cnt]=tmp;
            scanf("%d",&tmp);
        }
        map[0][i][9]=cnt;
    }
    DFS(1);  
    printf("-1");
    return 0;
}