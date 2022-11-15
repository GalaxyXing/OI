#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct Light{
    int pw,pos;
}lt[55];
int f[55][55][2];
int n,c;
int calc(int suml,int sumr,int tl,int tr){
    return (lt[suml-1].pw+lt[n].pw-lt[sumr].pw)*(lt[tr].pos-lt[tl].pos);
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>lt[i].pos>>lt[i].pw;
        lt[i].pw+=lt[i-1].pw;
    }
    memset(f,0x3f,sizeof(f));
    f[c][c][0]=f[c][c][1]=0;
    for(int len=2;len<=n;len++){
        for(int l=1,r=l+len-1;r<=n;l++,r++){
            f[l][r][0]=std::min(f[l+1][r][0]+calc(l+1,r,l,l+1),f[l+1][r][1]+calc(l+1,r,l,r));
            f[l][r][1]=std::min(f[l][r-1][1]+calc(l,r-1,r-1,r),f[l][r-1][0]+calc(l,r-1,l,r));
        }
    }
    
    cout<<std::min(f[1][n][1],f[1][n][0]);
    return 0;
}