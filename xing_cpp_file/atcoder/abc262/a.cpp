#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
    int x;
    cin>>x;
    if((x-2)%4==0)cout<<x;
    else cout<<(x-2)/4*4+6;
    return 0;
}