#include<iostream>
using namespace std;
int T,n,k,a[20000],cnt;
void print(int x[]){
    int i=1;
    while(x[i]!=0){
        cout<<x[i]<<' ';
        i++;
    }cout<<endl;
}
bool check(int x,int y){
    for(int i=1;i<y;i++){
        if(x+a[i]==k+1)return false;
    }
    return true;
}
void dfs(int x){
    if(x>n){
        cnt++;
    //    print(a);
        return;
    }
    for(int i=a[x-1];i<=k;i++){
        if(x==1){
            a[x]=i;
            dfs(x+1);
        }
        else if(check(i,x)){
            a[x]=i;
            dfs(x+1);
        }
    }
}
int main(){
    cin>>T;
    a[0]=1;
    while(T--){
        cnt=0;
        cin>>n>>k;
        dfs(1);
        cout<<cnt<<endl;
    }
}