#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n,m,ans=0x7ffffffffffffff,checkans;
struct person{
    int p,c;
    bool operator<(const person &x)const{
        return c<x.c;
    }
}a[3005];
struct PARTY{
    int cnt,add;
    vector<int> member,sum;
}party[3005];
vector<int>minor;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].c;
        party[a[i].p].cnt++;
        party[a[i].p].member.push_back(a[i].c);
    }
    for(int i=2;i<=m;i++){        
        if(party[i].cnt>0){
            // cout<<" i "<<i<<endl;
            sort(party[i].member.begin(),party[i].member.end());
            party[i].sum.push_back(party[i].member[0]);
            // cout<<party[i].sum.back()<<" j "<<0<<endl;
            for(int j=1;j<party[i].member.size();j++){
                party[i].sum.push_back(party[i].sum.back()+party[i].member[j]);
                // cout<<party[i].sum.back()<<" j "<<j<<endl;
            }
        } 
    }
    sort(a+1,a+1+n);
    for(int i=max(party[1].cnt,1ll);i<=n;i++){
        checkans=0;
        int cntvote=0;
        minor.clear();
        // cout<<" i "<<i<<endl;
        for(int j=2;j<=m;j++){
            party[j].add=0;
            if(party[j].cnt>=i){
                cntvote+=party[j].cnt-i+1;
                checkans+=party[j].sum[party[j].cnt-i];    
                // cout<<checkans<<endl;
                party[j].add=party[j].cnt-i+1;
            }else continue;
        }
        if(cntvote<i-party[1].cnt){
            for(int j=2;j<=m;j++){
                for(int k=party[j].add;k<party[j].cnt;k++){
                    minor.push_back(party[j].member[k]);
                }
            }
            // cout<<"minor "<<minor.size()<<endl;
            sort(minor.begin(),minor.end());
            int pointer=0;
            // for(int k=0;k<minor.size();k++)cout<<minor[k]<<" ";
            // cout<<endl;
            while(cntvote<i-party[1].cnt){
                // cout<<" pointer "<<pointer<<endl;
                cntvote++;
                checkans+=minor[pointer];
                pointer++;
            }
        }
        // cout<<" checkans "<<checkans<<endl;
        ans=min(ans,checkans);
    }
    cout<<ans;
    return 0;
}
