#include<cstdio>
int lower[100005],cntlower,upper[100005],cntupper;
int bomb[100005],n=0;
int find_upper(int x,int l,int r){
    int mid=l+r>>1;
    while(r-l>1)mid=l+r>>1,(upper[mid]>=x)?r=mid:l=mid;
    return r;
}
int find_lower(int x,int l,int r){
    int mid=l+r>>1;
    while(r-l>1)mid=l+r>>1,(lower[mid]<x)?r=mid:l=mid;
    return r;
}
int main(){
	while(scanf("%d ",&bomb[n+1])!=EOF){n++;}
    lower[++cntlower]=upper[++cntupper]=bomb[1];
	for(int i=2;i<=n;i++)(bomb[i]<=lower[cntlower])?lower[++cntlower]=bomb[i]:lower[find_lower(bomb[i],0,cntlower)]=bomb[i];
    printf("%d\n",cntlower);
	for(int i=2;i<=n;i++)(bomb[i]>upper[cntupper])?upper[++cntupper]=bomb[i]:upper[find_upper(bomb[i],0,cntupper)]=bomb[i];
    printf("%d",cntupper);
 //   getchar();
	return 0;
}