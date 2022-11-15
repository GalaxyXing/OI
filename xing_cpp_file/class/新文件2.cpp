#include <cstdio>
using namespace std;
long long ans[130000][35];
int geshu_1[130000];
#define MOD 998244353
int v[105];
int n, m, k;
long long  ansall;

long long pre(long long x) {
	if (x == 1)
		return geshu_1[x] = 1;
	else if (geshu_1[x] != 0)
		return geshu_1[x];
	else
		return geshu_1[x] = pre(x >> 1) + (x & 1);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 1; i <= n * (1ll << m); i++) {
		pre(i);
	}
	for (int i = 0; i <= m; i++) {
		ans[1 << i][1] = v[i];
	}
	for (int i = 1; i <= n * (1ll << m); i++) {
		for (int j = 2; j <= n; j++) {
			for (int q = 0; q <= m && (1 << q) <= i; q++) {
				ans[i][j] += ans[i - (1 << q)][j - 1] * v[q];
				ans[i][j] %= MOD;
			}
		}
		//	printf("%d %d\n", geshu_1[i], i);
		if (geshu_1[i] <= k && i >= n) {
			ansall += ans[i][n];
			ansall %= MOD;
		}
	}
	printf("%lld", ansall);
	return 0;
}