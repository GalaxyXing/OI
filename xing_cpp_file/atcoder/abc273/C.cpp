#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a[200005],uni[200005],n,larg[200005];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],uni[i]=a[i];
    std::sort(uni+1,uni+1+n);
    int len=std::unique(uni+1,uni+1+n)-uni-1;
    for(int i=1;i<=n;i++){
        int pos=std::lower_bound(uni+1,uni+1+len,a[i])-uni;
        larg[len-pos]++;
    }
    for(int i=0;i<=n-1;i++){
        cout<<larg[i]<<endl;
    }
    return 0;
}