#include<iostream>
using namespace std;
int n,m,sq[23][23];
void change(int x,int y){
    for(int i=1;i<=n;i++){
        swap(sq[i][x],sq[i][y]);
    }
}
bool check(int x,int y){
    change(x,y);
    for(int i=1;i<=n;i++){
        int dif=0;
        for(int j=1;j<=m;j++){
            dif+=(sq[i][j]!=j);
        }
        if(dif>2)return change(x,y),false;
    }
    return change(x,y),true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>sq[i][j];
        }
    }
    if(check(0,0)){
        cout<<"YES";
        return 0;
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            if(check(i,j)){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}