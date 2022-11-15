#include<cstdio>
#include<cmath>
#define INF 0x7fffffff
int n;
struct CHESSE{
    double x,y;
}ch[20];
double dp[20][(1<<16)+5];
double dis(CHESSE a,CHESSE b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&ch[i].x,&ch[i].y);
    
}