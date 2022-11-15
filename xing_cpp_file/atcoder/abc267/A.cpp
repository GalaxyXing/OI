#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::map<std::string ,int> m;
int main(){
    m["Monday"]=1;
    m["Tuesday"]=2;
    m["Wednesday"]=3;
    m["Thursday"]=4;
    m["Friday"]=5;    
    std::string t;
    cin>>t;
    cout<<6-m[t];
    return 0;
}