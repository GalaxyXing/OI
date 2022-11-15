#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node{
    char x;
    int y;
};
vector<node>aa,bb;
int main(){
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size()){
        cout<<"No";
        return 0;
    }
    char t=a[0];
    int cnt=1;
    for(int i=1;i<a.size();i++){
        if(a[i]==t)cnt++;
        else aa.push_back({t,cnt}),t=a[i],cnt=1;
    }
    aa.push_back({t,cnt});
    t=b[0],cnt=1;
    for(int i=1;i<b.size();i++){
        if(b[i]==t)cnt++;
        else bb.push_back({t,cnt}),t=b[i],cnt=1;
    }
    bb.push_back({t,cnt});
    if(aa.size()!=bb.size()){
        cout<<"No";
        return 0;
    }
    else{
        for(int i=0;i<aa.size();i++){
            if(aa[i].x!=bb[i].x){
                cout<<"No";
                return 0;
            }
        }
        for(int i=0;i<aa.size();i++){
            if(aa[i].y==1&&bb[i].y>1){
                cout<<"No";
                return 0;
            }else if(bb[i].y<aa[i].y){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
}