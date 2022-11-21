#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=4e5+10;
bool cmp(int a,int b)
{
	return a>b;
}
int a,b;
int n;
int h[N],e[N],ne[N],w[N],idx;
int f[N],g[N];
map<int,int>m1;
map<int,int>m2;
void add(int a,int b,int c)
{
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void sou1(int u,int x,int fa){
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(j==fa)continue;
		m1[j]=x^w[i];
		sou1(j,x^w[i],u);
	}
}
int xx=-1;
void sou2(int u,int x,int fa)
{
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(j==fa)continue;
		if(j==b)xx=x^w[i];
		m2[j]=x^w[i];
		sou2(j,x^w[i],u);
	}
}
signed main()
{
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
	int t=read();
	while(t--)
	{
		m1.clear();
		m2.clear();
		memset(h,-1,sizeof h);
		n=read(),a=read(),b=read();
		for(int i=1;i<=n-1;i++)
		{
			int a=read(),b=read(),x=read();
			add(a,b,x);
			add(b,a,x);
		}
		sou1(b,0,-1);
		sou2(a,0,-1);
		bool flag=false;
		cout<<xx<<"\n";
		if(xx==0)puts("YES");
		else{
			for(int i=1;i<=n;i++)
				if(i!=b&&m1[i]==m2[i])
				{
					flag=true;
					break;
				}
			if(flag)
			{
				puts("YES2");
			}else puts("NO");
		}
		
	}
	return 0;
}
