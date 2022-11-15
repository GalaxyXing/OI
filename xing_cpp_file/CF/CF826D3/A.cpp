#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
char solve(){
    std::string s1,s2;
    cin>>s1>>s2;
    if(s1.back()=='L'&&(s2.back()=='M'||s2.back()=='S'))return '>';
    else if(s1.back()=='M'&&s2.back()=='S') return '>';
    else if(s1.back()=='L'&&s2.back()=='L'){
        if(s1.size()>s2.size())return '>';
        else if(s1.size()==s2.size())return '=';
        else return '<';
    }else if(s1.back()==s2.back()&&s1.back()=='M')return '=';
    else if(s1.back()==s2.back()&&s1.back()=='S'){
        if(s1.size()>s2.size())return '<';
        else if(s1.size()==s2.size())return '=';
        else return '>';
    }else return '<';
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}