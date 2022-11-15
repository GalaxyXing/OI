#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
int n;
int a[300005];
std::deque<int> q;
signed main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>n)a[n+1]++;
        else a[x]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i])q.push_back(i),a[i]--;
    }
    for(int i=1;i<=n+1;i++){
        while(a[i])q.push_back(i),a[i]--;
    }
    int ans=0;
    if(q.size()==1){
        if(q.front()==1){
            cout<<1;
            return 0;
        }else {
            cout<<0;
            return 0;
        }
    }
    while(!q.empty()){
        if(q.front()==ans+1){
            ans++,q.pop_front();
        }else{
            if(q.size()>1){
                ans++;
                q.pop_back();
                q.pop_back();
            }else break;
        }
    }
    cout<<ans;
    return 0;
}