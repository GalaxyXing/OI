#include<iostream>
#include<vector>
using namespace std;
int n,m,N,ans,dp1[105][105],sum[105][105]/*ÿһ���ǰ׺��*/,dp2[105][10005];
vector<int> a[105];
int cal(int k,int i,int j) //�� k ��ȡ��ǰ i ���ͺ� j �����ܼ�ֵ
{
	int N=a[k].size();
	return sum[k][N]-sum[k][N-j]+sum[k][i];
}
int main()
{
	int N,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>N;
		for(int k=1;k<=N;k++)
			cin>>x,a[i].push_back(x),sum[i][k]=sum[i][k-1]+x;//��Ϊÿһ�㳤�Ȳ�������һ��vector���棬ͬʱ����ǰ׺��
	}
	for(int k=1;k<=n;k++)
		for(int l=1;l<=a[k].size();l++)
			for(int i=0;i<=l;i++) {int j=l-i;dp1[k][l]=max(dp1[k][l],cal(k,i,j));}
            //dp1ת��
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=a[i].size();j++){
    //         printf("i %d j %d shelf %d\n",i,j,dp1[i][j]);
    //     }
    // }
	for(int k=1;k<=n;k++)
		for(int i=0;i<=m;i++)
			for(int j=0;j<=a[k].size() && j<=i;j++)
				dp2[k][i]=max(dp2[k][i],dp2[k-1][i-j]+dp1[k][j]);//dp2ת��
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("i %d j %d dp %d\n",i,j,dp2[i][j]);
        }
    }
    cout<<dp2[n][m];
	return 0;
}
