#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::multiset<int> ms;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        freopen("test.err","w",stderr);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ms.insert(x);
    }
    int cnt=0;
    while(ms.size()>1){
        auto itr_mx=(ms.end());
        itr_mx--;
        int mx=*itr_mx;
    //    cout<<mx<<" ";
        ms.erase(itr_mx);
        auto itr_mn=(ms.begin());
        int mn=*itr_mn;
    //    cout<<mn<<endl;
        if(mx%mn!=0)ms.insert(mx%mn);
        cnt++;
    }
    cout<<cnt;
    return 0;
}