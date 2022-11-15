#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
double a[300005];
int buc[1000006],bucmax,cnta;
int n;
bool cmp(int x,int y){return x>y;}
int main(){
	#ifdef LOCAL
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		bucmax=std::max(bucmax,x);
		buc[x]++;
	}
	for(int i=bucmax;i;i--){
		while(buc[i]--)cnta++,a[cnta]=a[cnta-1]+i;
	}
	for(int i=1;i<=n;i++){
		a[i]*=a[i]/i;
	}
	double max=0;
	for(int i=1;i<=n;i++){
		max=std::max(max,a[i]);
	}
	printf("%.8lf",max);
	return 0;
}
