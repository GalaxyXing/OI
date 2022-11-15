//∏ﬂ“ª–œ–¿—Ù 2.” ∆±
#include <iostream>
#include <algorithm>
using namespace std;
int dp[2000050];
int a[205], maxa;
int k, n;

int main() {
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > maxa)
			maxa = a[i];
	}
	sort(a + 1, a + 1 + n);
	dp[0] = 0;
	int MAX = maxa * k;
	if (a[1] != 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= MAX; i++) {
		dp[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= MAX; j++) {
			dp[j] = min(dp[j - a[i]] + 1, dp[j]);
		}
	}
	int m;
	for (int i = 1; i <= MAX; i++) {
		//	cout << dp[i] << ' ';
		if (dp[i] > k) {
			m = i - 1;
			break;
		}

		else
			m = i;
	}
	cout << m;
	return 0;
}