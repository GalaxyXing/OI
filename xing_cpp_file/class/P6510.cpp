#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,ans=0;
int a[100001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int now=n,mi=n;
    for(int i=n;i>=1;i--){
        if(a[i]>=a[now]){
            now=i;
            mi=i;
        }
        if(a[mi]>=a[now]){
            now=mi;
        }
        if(a[i]<a[mi]){
            mi=i;
        }
        if(now-mi+1>ans)ans=now-mi+1;
    }
    if(ans==1)cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}