#include<iostream>
using namespace std;
long long n,a,b,c;
int min(int a,int b){return a<b?a:b;}
int main(){
    cin>>n>>a>>b>>c;
    if (c<n)  cout<<(2*n-1);
    else cout<<min(2*n+b-a,n+c+c+1-n);
    return 0;
}