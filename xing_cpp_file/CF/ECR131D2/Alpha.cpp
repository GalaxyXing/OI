#include<iostream>
using namespace std;
int n,cnt;
int check(){
    cnt=0;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            int t;
            cin>>t;
            if(t==1)cnt++;
        }
    }
    if(cnt==0)return 0;
    else if(cnt==1||cnt==2||cnt==3)return 1;
    else return 2;
}
int main(){
    cin>>n;
    while(n--){
        cout<<check()<<endl;
    }
    return 0;
}