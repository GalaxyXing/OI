#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define int unsigned long long
using namespace std;
int T,n;
bool check(int x,int y){
    string a=to_string(x);
    reverse(a.begin(),a.end());
    int t=0;
    for(int i=0;i<a.size();i++){
        t=t*10ll+(a[i]-'0');
    }
    return t>n;
}
void bao_li(){
    int i=1;
    int t=n;
    while(t>0){
        t/=10ll;
        i*=10ll;
    }
    i/=10ll;
    for(;;i++){
        if(check(i,n))break;
    }
    cout<<i-1<<endl;
}
bool check9(int x){
    x+=1;
    while(x!=1){
        if(x%10!=0)return false;
        x/=10;
    }
    return true;
}
void zheng_jie(int x){
    vector<int> a;
    vector<int> b;
    while(x!=0){
        a.push_back(x%10ll);
        x/=10ll;
    }
    reverse(a.begin(),a.end());
    if(a.size()==1){
        if(n==9)cout<<10<<endl;
        else cout<<n<<endl;
        return;
    }
    int tflag=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=0)tflag++;
    }
    if(tflag==1){
        for(int i=0;i<a.size();i++){
            if(i==0){
                b.push_back(a[i]-1);
            }else{
                b.push_back(0);
            }
        }
        b[b.size()-1]=1;
        reverse(b.begin(),b.end());
        int out=0;
        for(int i=0;i<b.size();i++){
            out=out*10+b[i];
        }
        cout<<out<<"\n";
        return;
    }
    if(check9(n)){
        cout<<n+1<<endl;
        return;
    }
    bool flag=1;
    for(int i=0;i<a.size();i++){
        if(flag&&a[i]==9){
            if(i==0){
                b.push_back(8);
                continue;
            }
            b.push_back(9);
        }else if(flag==0){
            b.push_back(0);
        }else if(a[i]!=9){
            if(i==0){
                b.push_back(a[i]);
                flag=0;
                continue;
            }
            int ttflag=1;
            for(int j=i+1;j<a.size();j++){
                if(a[j]!=0){
                    ttflag=0;
                    break;
                }
            }
            if(i==a.size()-1)ttflag=0;
            if(ttflag==0)b.push_back(a[i]+1);
            else b.push_back(a[i]);
            flag=0;
        }
    }
    if(b.back()==0)b[b.size()-1]=1;
    reverse(b.begin(),b.end());
    int out=0;
    for(int i=0;i<b.size();i++){
        out=out*10+b[i];
    }
    cout<<out<<"\n";
}
signed main(){
     cin>>T;
     while(T--){
        int x;
        cin>>x;
        n=x;
        zheng_jie(n);
      //  bao_li();
     //   cout<<endl; 
     }
    return 0;
}