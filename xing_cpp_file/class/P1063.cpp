#include<cstdio>
int nl[105];
int dp[205][205];
int a[205][205];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",nl+i);
    for(int i=1;i<=n;i++){
        a[i][i]=nl[i];
        for(int j=1;j<n;j++){
            a[i][i+j]=a[i][i+j-1]
        }
    }
}