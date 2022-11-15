#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e7+200;
int n,cha[maxn];
long long ans;
int a[maxn],b[maxn];
int randseed;
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
    for(int i=1;i<=n;i++)cha[i]=a[i]-b[i];
    for(int i=1;i<n;i++){
        if(cha[i]<0){
            cha[i+1]+=cha[i];
            ans-=cha[i];  
        }              
    }
    printf("%lld",ans);
    return 0;
}
