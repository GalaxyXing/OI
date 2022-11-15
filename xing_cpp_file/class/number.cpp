//西安高新一中 SN-0108 邢欣阳 T1  报数 
#include<cstdio>
#define MAXNUM 200100
#define MAXB 10002500
using namespace std;
int T;
int num[MAXNUM];
bool isok[MAXB],isok2[MAXB];
int next[MAXB],last;
int maxn;
inline int max(int x,int y){
	return ((x>y)?x:y);
}
void pre(int x){
	for(int i=1;i<=x;i++){
		if(isok[i]==false){
			int tmp=i;
			//	printf("tmp %d i %d tmp%%10 %d\n",tmp,i,tmp%10);
			while(tmp){
				if(tmp%10==7){
					isok[i]=true;
					break;
				}else tmp/=10;
			}
		}
		if(isok[i]==false){
			next[last]=i;
			last=i;
		}else if(isok[i]==true){
			for(int j=2;j*i<=x;j++){
				isok[j*i]=true;
			}
		}			
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&num[i]);
		maxn=max(maxn,num[i]);		
	}	
//	printf("maxn %d\n\n",maxn);
	pre(maxn+1000);
	for(int i=1;i<=T;i++){
		if(isok[num[i]]){
			printf("-1\n");
		}else {
			printf("%d\n",next[num[i]]);
		}
	}	
	return 0;
}
