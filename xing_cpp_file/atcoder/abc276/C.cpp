#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::basic_string<int> a;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a+=x;
    }
    std::prev_permutation(a.begin(),a.end());
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}