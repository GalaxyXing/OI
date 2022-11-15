#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
int cnt,ans;
int vis[500005],a[500005],n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            cnt++;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(a[i]!=i){
            if(a[a[i]]==i){
                ans++;
                vis[i]=1,vis[a[i]]=1;
            }
        }
    }
    ans+=cnt*(cnt-1)/2;
    cout<<ans;
    return 0;
}