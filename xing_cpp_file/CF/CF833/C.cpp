#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define int long long
int sum[200005];
std::map<int,int> mp;
int calc(int l,int r){
    mp.clear();
    int re=0;
    for(int i=l;i<r;i++){
        mp[sum[i]]++;
    }
    for(auto p:mp){
        re=std::max(p.second,re);
    }
    return re;
}
int calc1(int l,int r){
    int re=0;
    for(int i=l;i<r;i++){
        if(sum[i]==0)re++;
    }
    return re;
}
void solve(){
    int n;
    cin>>n;
    std::basic_string<int> zpos;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum[i]=sum[i-1]+x;
        if(x==0)zpos+=i;
    }
    int bsize=zpos.size();
    int ans=0;
    if(bsize==0)ans+=calc1(1,n+1);
    else ans+=calc1(1,zpos[0]);
    for(int i=0;i<bsize-1;i++){
        ans+=calc(zpos[i],zpos[i+1]);
    }
    if(bsize)ans+=calc(zpos[bsize-1],n+1);
    cout<<ans<<"\n";
}
signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int t;
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}