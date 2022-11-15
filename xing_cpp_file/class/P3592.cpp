#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int n,m;
struct Person{
	int a,b,c;
}ct[4005];
int main(){
	#ifdef LOCAL
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ct[i].a>>ct[i].b>>ct[i].c;
	}
	return 0;
}