#include<iostream>
#include<vector>
using namespace std;
int n,q,x;
int w[200005],pointer;
int vis[200005],cntvis=1;
vector<int>myv;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q>>x;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int sum=0,cnt=0;
    while(sum<=x){
        sum+=w[pointer];
        cnt++;
        pointer++;
        pointer%=n;
    }
    pointer=(pointer+n-1)%n;
    myv.push_back(cnt);
    vis[pointer]=cntvis;   
    int circle=0; 
    while(true){
        cntvis++,pointer++;
        pointer%=n;
        sum=0,cnt=0;
        while(sum<x){
            sum+=w[pointer];
            cnt++;                
            pointer++;
            pointer%=n;
        }//cout<<" sum "<<sum<<endl;
        pointer=(pointer+n-1)%n;
        myv.push_back(cnt);
        if(vis[pointer]!=0){
            circle=cntvis-vis[pointer];
            break;
        }
        vis[pointer]=cntvis;
    }
    int size=myv.size();
    for(int i=1;i<=q;i++){
        long long k;
        cin>>k;
        if(k<=size)cout<<myv[k-1]<<'\n';
        else {
            k-=size;
            k%=circle;
            if(k==0)k=circle;
            cout<<myv[size-circle+k-1]<<'\n';
        }
    }
    return 0;
}