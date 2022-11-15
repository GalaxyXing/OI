#include<iostream>
#include<map>
using std::map;
using std::cin;
using std::endl;
using std::cout;
map<int,map<int,int> >m;
int n,q;
int main(){
    cin>>n>>q;
    while(q--){
        int swt,i,j;
        cin>>swt>>i>>j;
        if(swt==1){
            int k;
            cin>>k;
            m[i][j]=k;
        }else cout<<m[i][j]<<endl;
    }
    return 0;
}