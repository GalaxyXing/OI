#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
int N,M,Q,mod=998244353;
int solve(int a,int b,int c,int d){
    int T=(a-1)*M+c;
    int line=(T*((d-c)/2+1)%mod)+(1+(d-c)/2)*(d-c)/4%mod;
    line%=mod;
    int all=line*((b-a)/2+1);
    all+=(((M*((d-c)/2+1)%mod)*(b-a)/2)%mod)*(1+(b-a)/2);
    all%=mod;
    return all;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>N>>M;
    cin>>Q;
    while(Q--){
        int a,b,c,d;
        int aa,bb,cc,dd;
        cin>>a>>b>>c>>d;
        aa=a+1;
        bb=b-1;
        cc=c+1;
        dd=d-1;
        int ans=0;
        if((a+c)%2==1&&(b+d)%2==1){
            if(aa<=bb)ans+=solve(aa,bb,c,d);
            if(cc<=dd)ans+=solve(a,b,cc,dd);
        }else if((a+c)%2==1&&(b+d)%2==0){

        }
    }
    return 0;
}