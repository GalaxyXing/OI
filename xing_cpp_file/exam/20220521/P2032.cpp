#include<cstdio>
#include<deque>
using namespace std;
inline int read(){
    int re=0;
    char t=getchar();
    while(t<'0'||t>'9')t=getchar();
    while(t>='0'&&t<='9')re=(re<<3)+(re<<1)+(t^48),t=getchar();
    return re;
}
int n,k,a[2000006];
int q[2000006];
int main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int h=1,t=0,i=1;i<=n;i++){
        while(q[h]+k<=i&&h<=t)h++;
        while(h<=t&&a[q[t]]<=a[i])t--;
        q[++t]=i;
        if(i>=k)printf("%d\n",a[q[h]]);
    }
    return 0;
}