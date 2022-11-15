#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
__int128 dp[85][85],ans;
__int128 base2[85];
int mp[85][85];
int n,m;
template<typename _T>
void write(_T x){
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
__int128 solve(int x){
	for(int i=1;i<=m;i++){
		dp[i][i]=mp[x][i]*base2[m];
		// cout<<x<<" "<<i<<" "<<i<<" ";
		// write(dp[i][i]);
		// cout<<endl;
	}
	for(int len=2;len<=m;len++){
		for(int l=1,r=l+len-1;r<=m;l++,r++){
			dp[l][r]=std::max(dp[l+1][r]+mp[x][l]*base2[m-len+1],dp[l][r-1]+mp[x][r]*base2[m-len+1]);
			// cout<<x<<" "<<l<<" "<<r<<" ";
			// write(dp[l][r]);
			// cout<<endl;
		}
	}
	return dp[1][m];
}
int main(){
	#ifdef LOCAL
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	base2[0]=1;
	for(int i=1;i<=m;i++){
		base2[i]=base2[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof(dp));
		ans+=solve(i);
	}
	write(ans);
	return 0;
}