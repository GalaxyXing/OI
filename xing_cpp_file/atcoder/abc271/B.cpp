#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::vector<int> v[200005];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int ln;
        cin>>ln;
        for(int j=1;j<=ln;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
        //std::sort(v[i].begin(),v[i].end());
    }
    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        cout<<v[s][t-1]<<endl;
    }
    return 0;
}