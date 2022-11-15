#include<iostream>
#define int long long
using namespace std;
int n,m;
int a[200005];
bool check(int x){
    int cnt=0;
    int left=0;
    for(int i=1;i<=n;i++){
       // cout<<a[i]<<' ';
        if(a[i]>x)cnt+=a[i]-x;
        else if(a[i]<x)left+=((x-a[i])/2);
    }//cout<<endl;
    return left>=cnt;
}
signed main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i]=0;
        }
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        int l=0,r=m*2+1;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid;
        }
        cout<<r<<"\n";
    }
}