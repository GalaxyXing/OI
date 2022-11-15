//高一邢欣阳 3.小朋友的数字
#include <iostream>
#include <algorithm>
using namespace std;
long long n, p;
long long a[1000050], dp[1000050], tz[1000050], qz[1000050], dpp[1000050];
int ipos;

int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dpp[1] = dp[1] = qz[1] = tz[1] = a[1], ipos = 1;
	for (int i = 2; i <= n; i++) {
		if (qz[i - 1] < 0)
			qz[i] = a[i];
		else
			qz[i] = qz[i - 1] + a[i];
	}
	for (int i = 2; i <= n; i++) {
		tz[i] = max(tz[i - 1], qz[i]);
	}
//	for (int i = 1; i <= n; i++) {
//		cout << tz[i] << ' ' << i << endl;
//	}
	for (int i = 2; i <= n; i++) {
		dpp[i] = dp[i - 1] + tz[ipos];
		if (dpp[i] >= dp[i - 1]) {
			ipos = i;
			dp[i] = dpp[i];
		} else {
			dp[i] = dp[i - 1];
		}
	}
	bool flag = 0;
	if (dp[n] < 0) {
		flag = true;
	}
	long long ans = (!flag) ? dp[n] : -dp[n];
	ans %= p;
	cout << ans*((flag) ? -1 : 1);
	return 0;
}