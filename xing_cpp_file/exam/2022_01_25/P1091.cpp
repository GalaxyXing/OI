#include<cstdio>
int n,t[105],upper[105],lower[105];
int max(int x,int y){
    return (x>y)?x:y;
}
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",t+i);
        upper[i]=lower[i]=1;
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(t[i]>t[j])upper[i]=max(upper[i],upper[j]+1);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>i;j--){
			if(t[i]>t[j])lower[i]=max(lower[i],lower[j]+1);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,lower[i]+upper[i]-1);
	}
    printf("%d",n-ans);
    return 0;
}