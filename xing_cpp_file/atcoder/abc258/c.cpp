#include<iostream>
#include<string>
using namespace std;
int pointer=0,n,q;
string s;
int main(){
    cin>>n>>q;
    cin>>s;
    while(q--){
        int swt,x;
        cin>>swt>>x;
        if(swt==2){
            cout<<s[(pointer+x-1)%n]<<endl;
        }else if(swt==1){
            pointer+=n;
            pointer-=x;
            pointer%=n;
        }
    }
    return 0;
}