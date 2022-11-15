#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n&1){
            printf("%d\n",(n+1)>>1);
        }else{
            printf("%d\n",n>>1);
        }
    }
    return 0;
}