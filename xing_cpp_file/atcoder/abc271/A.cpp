#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int a;
    cin>>a;
    int l=a%16;
    int h=a/16;
    cout<<(char)(h>9?h+'A'-10:h+'0')<<(char)(l>9?l+'A'-10:l+'0');
    return 0;
}