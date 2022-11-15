#include<iostream>
using namespace std; 
unsigned long long L,R;
int main(){
    cin>>L>>R;
    if(R%2==0)cout<<R/2<<endl;
    else cout <<(R-1)/2<<endl;
    return 0;
}