#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a[270000];
int check(int l,int r,int &re){
    if(l==r&&l==1){
        return 0;
    }
    if(l<r-1){
        int mid=(l+r)>>1;
        int re1,re2;
        int x=check(l,mid,re1);
        //cout<<re1<<" "<<l<<" "<<mid<<" "<<x<<endl;
        int y=check(mid+1,r,re2);        
        //cout<<re2<<" "<<mid+1<<" "<<r<<" "<<y<<endl;
        if(x==-1||y==-1)return -1;
        else {
            int half=(r-l+1)/2;
            re1/=half;
            re2/=half;
            if(re1>re2){
                re=re1*half;
                if(re1%2==1)return -1;
                else if(re1-re2>1)return -1;
                else return x+y+1;
            }else{
                re=re2*half;
                if(re2%2==1)return -1;
                else if(re2-re1>1)return -1;
                else return x+y;
            }
        }
    }else{
        if(a[l]>a[r]){
            re=a[l];
            if(a[l]%2==1)return -1;
            else if(a[l]-a[r]>1)return -1;
            else return 1;
        }else{
            re=a[r];
            if(a[r]%2==1)return -1;
            else if(a[r]-a[l]>1)return -1;
            else return 0;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=0;
    cout<<check(1,n,t)<<endl;
    return;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}