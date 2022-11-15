#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::mt19937 rnd(time(nullptr));
inline int rd(int liml,int limr){
	#define __RANGE__ (limr-liml+1)
	#define __RND__ (std::abs((int)rnd()))
	int re=__RND__%__RANGE__+liml;
	return re;
}
int main(){
	freopen("E:\\code\\xing_cpp_file\\dp.in","w",stdout);
	int n=rd(1,100000);
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",rd(0,n),rd(0,n));
	}
	return 0;
}