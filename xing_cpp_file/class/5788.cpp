#include<iostream>
#include<stack>
using namespace std;
int a[3000005],f[3000005];
stack<int>s;
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(s.empty())s.push(i);
        else{
            while(!s.empty()&&a[s.top()]<a[i]){
                f[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<f[i]<<' ';
    }
    return 0;
}