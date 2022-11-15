#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
std::string a,b;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b;
        int l=m-1;
        for(int i=n-1;i>=0;i--){
            if(a[i]==b[l]){
                l--;
            }
            if(l==-1){
                cout<<"YES\n";
                break;
            }
        }
    }
}