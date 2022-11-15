#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using Person=std::pair<int,int>;
std::basic_string<Person> bs,p;
std::basic_string<int> val;
int dp[100005];
int n;
bool cmp2(const Person &x,const Person &y){
	return x.second<y.first;
}
int find(int l,int r){
	int q=r;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(p[mid].second<p[q].first)l=mid;
		else r=mid;
	}
	return l;
}
bool check(const Person &x){return x.second>=x.first;}
bool cmp(const Person &x,const Person &y){return x.second==y.second?x.first<y.first:x.second<y.second;}
int main(){
	freopen("E:/code/xing_cpp_file/dp.in","r",stdin);
	freopen("E:/code/xing_cpp_file/dp.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;		
		if(l+r>=n)continue;
		l++,r=n-r;
		p+=std::make_pair(l,r);
	}
	std::sort(p.begin(),p.end(),cmp);
	for(auto i:p)if(check(i))bs+=i;
	if(bs.empty()){
		cout<<n<<endl;
		return 0;
	}
	Person cmp=bs.front();
	p.clear();
	p+=cmp;
	val+=1;
	for(int i=1;i<bs.size();i++){
		if(bs[i]==cmp)val.back()++;
		else{
			cmp=bs[i];
			p+=cmp;
			val+=1;
		}
	}
	for(int i=0;i<p.size();i++){
		val[i]=std::min(p[i].second-p[i].first+1,val[i]);
	}
	dp[1]=val.front();
	//cout<<dp.back()<<endl;
	for(int i=2;i<=val.size();i++){
		int nxt=find(-1,i-1);
		// cout<<i<<" "<<nxt<<endl;
		if(nxt==-1)dp[i]=std::max(dp[i-1],val[i-1]);
		else dp[i]=std::max(dp[i-1],dp[nxt+1]+val[i-1]);
		//cout<<dp.back()<<endl;
	}
	// for(int i=1;i<=val.size();i++){
	// 	cout<<dp[i]<<endl;
	// 	cout<<val[i-1]<<endl;
	// }
	// cout<<val.size()<<endl;
	cout<<n-dp[val.size()];
	return 0;
}