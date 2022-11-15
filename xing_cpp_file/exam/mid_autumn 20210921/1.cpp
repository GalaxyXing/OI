//¸ßÒ»ÐÏÐÀÑô 1.Î§À¸Ä¾×®
#include <iostream>
#include <algorithm>
using namespace std;
int m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin >> m;
	for (int k = 1; k <= m; k++) {
		int n;
		cin >> n;
		int h[n + 5] = {};
		int dp[n + 5] = {};
		int ct[n + 5] = {};
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
			dp[i] = 1;
			ct[i] = 1;
			for (int j = 1; j < i; j++) {
				if (h[i] >= h[j]) {
					if (dp[j] + 1 > dp[i])
						dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] != 1) {
				ct[i] = 0;
			}
			for (int j = 1; j < i; j++) {
				if (h[i] >= h[j]) {
					if (dp[j] + 1 == dp[i]) {
						ct[i] += ct[j];
					}
				}
			}
		}
		//	for (int i = 1; i <= n; i++) {
		//	cout << dp[i] << ' ';
		//	}
		///	for (int i = 1; i <= n; i++) {
		//	cout << ct[i] << ' ';
		//	}
		//	cout << endl;
		int ipos = 0;
		int maxdp = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[i] >= maxdp) {
				ipos = i;
				maxdp = dp[i];
			}
		}
		cout << maxdp << ' ' << ct[ipos] << endl;
	}
	return 0;
}



