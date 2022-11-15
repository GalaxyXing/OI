#include<iostream>
#include<map>
#include<cmath>
#define int long long
using namespace std;
int t;
map<int,int> prime;
map<int,int> primemin;
typedef map<int,int>::iterator mit;
int min(int x,int y){return x<y?x:y;}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		int x,z;
		cin>>x>>z;
		if(z%x!=0){
			cout<<"-1\n";
			continue;
		}
		if(z==x){
			cout<<"1\n";
			continue;
		}
        //read&init
        int tmp=gcd(z/x,x*x);
        int tmp2=(int)sqrt(tmp);
        if(tmp2*tmp2!=tmp)cout<<"-1\n";
        else cout<<z/(x*tmp)*tmp2<<'\n';
	}
	return 0;
}