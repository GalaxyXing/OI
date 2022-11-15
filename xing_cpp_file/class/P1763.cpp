#include<vector>
#include<iostream>
#define int long long 
using namespace std;
int fabs(int x){return x>0?x:-x;}
struct FS{
    int a,b;
    FS (int x,int y):a(x),b(y){yf();}
    FS ():a(0),b(1){}
    int gcd(int x,int y)const{return (y==0)?fabs(x):gcd(fabs(y),(fabs(x)%fabs(y)));}
    int ceil(){return (b%a==0)?(b/a):(b/a+1);}
    void yf(){int t=gcd(a,b); a/=t,b/=t;}
    bool operator<(const FS &x)const{return (a*x.b)<(b*x.a);}
    bool operator<=(const FS &x)const{return (a*x.b)<=(b*x.a);}
    bool operator==(const FS &x)const{return (a==x.a)&&(b==x.b);}
    FS operator+(const FS &x)const{int t=gcd(b,x.b),fz=a*(x.b/t)+x.a*(b/t),fm=b/t*x.b;return FS(fz,fm);}
    FS operator-()const{return FS(-a,b);}
}st;
int max(int x,int y){return x>y?x:y;}
bool flag;
int limit;
vector<FS> ans,psb;
void print( vector<FS> x){for(auto i:x)cout<<i.b<<' ';}
bool check(FS x){return x.a==0;}
void dfs(int depth,int f){
    if(check(st)&&depth!=0)return;
    if(depth==0){
        if(check(st))flag=1;
        else return;
    }if(flag)return;
    for(int i=max(st.ceil(),f);;i++){
        FS minus(1,i);
        FS smallest(st.a,st.b*depth);
        if(minus<smallest)break;
        else if(minus<=st){
            st=st+(-minus);
            dfs(depth-1,i+1);
            st=st+minus;
        }
    }
}
void dfsans(int depth,int f){
    if(check(st)&&depth!=0)return;
    if(depth==0){
        if(ans.empty()&&check(st))ans=psb;
        else if((ans.back()<psb.back())&&check(st))ans=psb;
        return;
    }
    for(int i=max(st.ceil(),f);;i++){
        FS minus(1,i),smallest(st.a,st.b*depth);
        if(!ans.empty()){if(minus<ans.back())break;}
        if(minus<smallest)break;
        else if(minus<=st){
            st=st+(-minus);
            psb.push_back(minus);
            dfsans(depth-1,i+1);
            psb.pop_back();
            st=st+minus;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>st.a>>st.b;
    for(int i=1;;i++){
        if(flag==1){limit=i-1;break;}
        else dfs(i,2);
    }
    dfsans(limit,2);
    print(ans);
    return 0;
}