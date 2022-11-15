#include<iostream>
#include<set>
using namespace std;
int n,a[3000005],all,ans;
set<int> s[20],son[20];
void divide(int x){
    int cnt=0;
    for(int i=0;i<=n;i++)s[i].clear(),son[i].clear();
    for(int i=0;i<n-1;i++){
        s[cnt].insert(a[i+1]);
        if(((1<<i)&x)!=0)cnt++;
    }
    s[cnt].insert(a[n]);
    all=cnt;
}
void sol(int x){
    for(auto i=s[x].begin();i!=s[x].end();i++){
        bool flag=1;
        for(auto j=s[x].begin();j!=s[x].end();j++){
            if(i==j)continue;
            if(((*i)|(*j))==(*j)){
                flag=0;
                break;
            }
        }
        if(flag)son[x].insert(*i);
    }
}
bool check(int x,int y){
    if(son[x].size()!=son[y].size())return false;
    else {        
        for(auto i=son[x].begin(),j=son[y].begin();i!=son[x].end();i++,j++){
            if((*i)!=(*j))return false;
        }
        return true;
    }
}
bool solve(){
    for(int i=0;i<=all;i++){
        sol(i);
    }
    for(int i=0;i<all;i++){
        for(int j=i+1;j<=all;j++){
            if(!check(i,j))return false;
        }
    }
    return true;
}
int main(){
    cin>>n;
    if(n>10){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<(n-1));i++){
        divide(i);
        if(solve())ans++;
    }
    cout<<ans;
    return 0;
}