#include<bits/stdc++.h>
using std::cout;
using std::endl;
void print(int x,std::string s){
    if(x==6)cout<<"<font color=0x"<<s<<">"<<s<<"</font>";
    else{
        for(int i=0;i<16;i++){
            char t=(i<10?i+'0':i+'a'-10);
            print(x+1,s+t);
            if(x==5)cout<<" ";
            else cout<<endl;
        }
    }
}
int main(){
    freopen("test.md","w",stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(nullptr);
    std::string s="";
    print(0,s);
    return 0;
}