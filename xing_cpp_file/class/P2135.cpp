#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int m,dp[55][55][1005];
struct rg{
	int co,len;
}rg[55];
int ccs[55];
int main(){
	#ifdef LOCAL
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>m;
	for(int i=1;i<=m;i++)cin>>rg[i].co;
	for(int i=1;i<=m;i++)cin>>rg[i].len;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(rg[i].co==rg[j].co)ccs[i]+=rg[j].len;
		}
	}
	memset(dp,0x80,sizeof(dp));
	for(int i=1;i<=m;i++){
		for(int j=0;j<=ccs[i];j++){
			dp[i][i][j]=(rg[i].len+j)*(rg[i].len+j);
		}
	}
	for(int len=2;len<=m;len++){
		for(int l=1,r=l+len-1;r<=m;l++,r++){
			for(int k=0;k<=ccs[r];k++){
				dp[l][r][k]=std::max(dp[l][r][k],dp[l][r-1][0]+(rg[r].len+k)*(rg[r].len+k));
			} 
			for(int k=l;k<r-1;k++){
				if(rg[k].co==rg[r].co){
					for(int s=0;s<=ccs[r];s++){
						dp[l][r][s]=std::max(dp[l][r][s],dp[l][k][s+rg[r].len]+dp[k+1][r-1][0]);
					}
				}
			}
		}
	}
	cout<<dp[1][m][0];
	return 0;
}