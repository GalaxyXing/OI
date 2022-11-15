#include<cstdio>
#define INF 0x7fffffff
using namespace std;
inline int read(){
    int re=0;
    char t=getchar();
    while(t<'0'||t>'9')t=getchar();
    while(t>='0'&&t<='9')re=(re<<3)+(re<<1)+(t^48),t=getchar();
    return re;
}
int a[105];
int dfs(int x){
    if(a[x]!=INF)return a[x];
    for(int i=0;i<x;i++){
        
    }

}
int l;
int stone[105],s,t,m;
int main(){
    l=read();
    s=read(),t=read(),m=read();
    for(int i=0;i<105;i++)a[i]=INF;
    for(int i=1;i<=m;i++){
        stone[i]=read();
    }
    stone[m+1]=l;
    printf("%d",dfs(m+1));
}