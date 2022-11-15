#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::string s;
typedef std::bitset<5001> bit5000;
bit5000 b[2];
int dp[5005][5005];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>s;
    cin>>s;
    int pos=s.size();
    std::string ans=s;
    for(int i=0;(unsigned)i<s.size();i++)if(s[i]=='p'){
        pos=i;
        break;
    }
    for(int i=pos;(unsigned)i<s.size();i++){
        std::string tmp=s;
        std::reverse(tmp.begin()+pos,tmp.begin()+i+1);
        for(int j=pos;j<=i;j++){
            if(tmp[j]=='p')tmp[j]='d';
            else tmp[j]='p';
        }
        if(tmp<ans)ans=tmp;
    }
    cout<<ans;
    return 0;
}