#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a,b,c,d;
char mp[15][15];
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    for(int i=0;i<=11;i++)mp[i][0]=mp[0][i]=mp[11][i]=mp[i][11]='.';
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<=11;i++){
        for(int j=0;j<=11;j++){
            if(mp[i][j+1]=='.'&&mp[i+1][j]=='.'&&mp[i+1][j+1]=='#')a=i+1,c=j+1;
            if(i>0&&j>0)if(mp[i][j-1]=='.'&&mp[i-1][j]=='.'&&mp[i-1][j-1]=='#')b=i-1,d=j-1;
        }
    }
    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
    return 0;
}