#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::string s;
    cin>>s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='a'){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}