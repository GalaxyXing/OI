#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct Ball{
    long long x,y,v;
}bl[1005];
int n,x0;
long long tot,f[1005][1005][2];
bool cmp(const Ball &x,const Ball &y){return x.x<y.x;}
bool check(){
    for(int i=1;i<=n;i++){
        if(bl[i].x==x0)return false;
    }
    return true;
}
long long calc(int vl,int vr,int tl,int tr){
    return (bl[vl-1].v+bl[n].v-bl[vr].v)*(bl[tr].x-bl[tl].x);
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n>>x0;
    for(int i=1;i<=n;i++)cin>>bl[i].x;
    for(int i=1;i<=n;i++)cin>>bl[i].y,tot+=bl[i].y;
    for(int i=1;i<=n;i++)cin>>bl[i].v;
    if(check())bl[++n].x=x0;
    std::sort(bl+1,bl+1+n,cmp);
    for(int i=1;i<=n;i++)bl[i].v+=bl[i-1].v;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        if(bl[i].x==x0){
            f[i][i][0]=f[i][i][1]=0;
            break;
        }
    }
    for(int len=2;len<=n;len++){
        for(int l=1,r=l+len-1;r<=n;l++,r++){
            f[l][r][0]=std::min(f[l+1][r][0]+calc(l+1,r,l,l+1),f[l+1][r][1]+calc(l+1,r,l,r));
            f[l][r][1]=std::min(f[l][r-1][0]+calc(l,r-1,l,r),f[l][r-1][1]+calc(l,r-1,r-1,r));
        }
    }
    //cout<<tot<<" "<<std::min(f[1][n][0],f[1][n][1]);
    printf("%.3lf",(0.001)*(tot-std::min(f[1][n][0],f[1][n][1])));
    return 0;
}