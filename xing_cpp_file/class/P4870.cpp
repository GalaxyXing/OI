#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int w[305],f[305][305][2];
int n,m,x0;
bool zo;
bool check(){
    for(int i=1;i<=n;i++){
        if(w[i]==0)return false;
    }
    return true;
}
int dp(int x){
    memset(f,0x3f,sizeof(f));
    f[x0][x0][0]=f[x0][x0][1]=0;
    for(int len=2;len<=x;len++){
        for(int l=1,r=l+len-1;r<=n;l++,r++){
            f[l][r][0]=std::min(f[l+1][r][0]+(w[l+1]-w[l])*(x-len+1),f[l+1][r][1]+(w[r]-w[l])*(x-len+1));
            f[l][r][1]=std::min(f[l][r-1][0]+(w[r]-w[l])*(x-len+1),f[l][r-1][1]+(w[r]-w[r-1])*(x-len+1));
        }
    }
    int res=0x3f3f3f3f;
    for(int l=1,r=l+x-1;r<=n;l++,r++){
        res=std::min(res,std::min(f[l][r][0],f[l][r][1]));
    }
    //cout<<"res "<<res<<endl;
    return res;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    if(check())zo=true,n++;
    std::sort(w+1,w+1+n);
    for(int i=1;i<=n;i++)if(!w[i]){
        x0=i;
        break;
    }
    int ans=-1;
    for(int lim=1;lim<=n;lim++){
        ans=std::max(ans,lim*m-dp(lim)-(zo?m:0));
    }
    cout<<ans;
    return 0;
}