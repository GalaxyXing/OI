#include<iostream>
using namespace std;
int main(){
    int n,m,x,t,d;
    cin>>n>>m>>x>>t>>d;
    int h;
    if(n<x)h=(x-n)*d+t;
    else h=t;
    if(m>=x)cout<<h<<endl;
    else cout<<h-(x-m)*d;
    return 0;
}