#include<cstdio>
int max(int x,int y){return (x>y)?x:y;}
struct HD{
    int length,dgt[100];
    HD operator*(const HD &x)const{
        HD answer={0,{}};
        if(x.length==0||length==0)return answer;
        int up=0,tmp;
        for(int i=1;i<=x.length;i++)
        for(int j=1;j<=length;j++)
        answer.dgt[i+j-1]+=x.dgt[i]*dgt[j];        
        for(int i=1;i<=x.length+length;i++)tmp=answer.dgt[i]+up,answer.dgt[i]=tmp%10,up=tmp/10;
        int cur=x.length+length;
        while(answer.dgt[cur]==0&&cur>0)cur--;
        answer.length=cur;
        return answer;
    }
    bool operator<(const HD &x)const{
        if(x.length==length){
            for(int i=length;i>=1;i--)
            if(x.dgt[i]!=dgt[i])
            return dgt[i]<x.dgt[i];
        }
        return length<x.length;
    }    
    void print(){for(int i=length;i>=1;i--)putchar((dgt[i]+'0'));}
}dp[50][10],a[50][50];
char b[50];
int n,k;
HD cut(int x,int y){
    HD tmp={};
    int cur=x;
    while(b[cur]=='0'&&cur<=y)cur++;
    tmp.length=y-cur+1;
    for(int i=cur;i<=y;i++)tmp.dgt[y-i+1]=b[i]-'0';
    return tmp;
}
HD max(HD x,HD y){return (x<y)?y:x;}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",b+1);
    for(int i=1;i<=n;i++){
        dp[i][0]=cut(1,i);
        for(int j=i;j<=n;j++)a[i][j]=cut(i,j);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int cur=1;cur<i;cur++)dp[i][j]=max(dp[i][j],dp[cur][j-1]*a[cur+1][i]);
        }
    }
    dp[n][k].print();
    return 0;
}