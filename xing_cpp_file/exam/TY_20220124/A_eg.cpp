#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e7+10;
int a[maxn],b[maxn];
int randseed,n;
unsigned int rnd()
{
  unsigned int r;
  r = randseed = randseed * 1103515245 + 12345;
  return (r << 16) | ((r >> 16) & 0xFFFF);
}
int main()
{
	cin>>n>>randseed;
	int sum=0;
	for (int i=n;i>=1;i--)
	{
		a[i]=rnd()%1000,b[i]=rnd()%1000;
		if (sum+(a[i]-b[i])<0) swap(a[i],b[i]);
		sum+=(a[i]-b[i]);
	}
    freopen("a.txt","w",stdout);
    for(int i=1;i<=n;i++){
        printf("%d ",)
    }
}