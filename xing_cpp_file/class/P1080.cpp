#include<iostream>
#include<deque>
#include<algorithm>
#define int long long
using namespace std;
struct LARGE{
    deque<int> a;
    int l,r;
    LARGE operator*(const int &x)const{
        LARGE tmp;
        tmp.l=l,tmp.r=r;
        deque<int> ans(a.size()+30);
        for(int i=a.size()-1;i>=0;i--){
            ans[i+20]+=a[i]*x;
            ans[i+19]+=ans[i+20]/10;
            ans[i+20]%=10;
        }
        int tag=0;
        for(int i=19;i>=0;i--){
            if(ans[i]>10){
                ans[i-1]=ans[i]/10;
                ans[i]%=10;
            }
        }
        while(ans.front()==0)ans.pop_front();
        tmp.a=ans;
        return tmp;
    }
    bool operator<(const LARGE &x)const{
        if(a.size()<x.a.size())return true;
        else if(a.size()>x.a.size())return false;
        else{
            for(int i=0;i<a.size();i++){
                if(a[i]<x.a[i])return true;
                else if(a[i]>x.a[i])return false;
            }
            return false;
        }
    }
    LARGE operator/(const int &x)const{
        LARGE tmp;
        tmp.l=l,tmp.r=r;
        deque<int> ans(a.size()+10);
        for(int i=0;i<a.size();i++){
            ans[i]=a[i]/x;
            if(i+1<a.size())ans[i+1]+=(a[i]%x)*10;
        }
        while(ans.front()==0)ans.pop_front();
        tmp.a=ans;
        return tmp;
    }
}minister[1005],king;
bool cmp(LARGE x,LARGE y){
    return x.l*x.r<y.l*y.r;
}
int n;
signed main(){
    cin>>n;
    cin>>king.l>>king.r;
    for(int i=1;i<=n;i++){
        cin>>minister[i].l>>minister[i].r;
    }
    sort(minister+1,minister+n+1,cmp);
    
}