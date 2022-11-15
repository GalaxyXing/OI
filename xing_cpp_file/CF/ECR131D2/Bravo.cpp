#include<iostream>
#include<vector>
using namespace std;
int q,n,a[200005];
bool flag[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>q;
    while(q--){
        cin>>n;
        cout<<2<<"\n";
        int cnt=0;
        for(int i=1;i<=n;i++){
            a[i]=0,flag[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(flag[i]==1)continue;
            else{
                int tmp=i;
                while(tmp<=n){
                    a[++cnt]=tmp;
                    flag[tmp]=1;
                    tmp*=2;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }cout<<"\n";
    }
    return 0;
}