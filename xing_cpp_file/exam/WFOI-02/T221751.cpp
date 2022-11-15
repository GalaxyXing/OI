#include<iostream>
#include<bitset>
using namespace std;
int n,m;
int cntm[105],map[105][105],match[105][105];
bitset<105>tmp_match[3];
void solve(int up,int down){
    for(int i=1;i<=m;i++){
        tmp_match[1][i]=match[up][i];
        tmp_match[2][i]=match[down][i];
    }
    if(tmp_match[1].none()&&tmp_match[2].none())return;
    
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>map[i][j],cntm[map[i][j]]++;
            if (map[i][j]!=j&&map[i][j]!=m-j+1){
                cout<<"NO";
                return 0;
}
        }
    for(int i=1;i<=m;i++)
        if (cntm[i]!=n){
            cout<<"NO";
            return 0;
}   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            match[i][j]=(map[i][j]==m-j+1);
        }
    }
    for(int i=1;i<=n/2;i++){
        solve(i,n-i+1);
    }
}