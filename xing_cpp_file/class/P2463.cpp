#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int xl[1005], cf[1005][105], minm = 0x7fff, n, ans, m[1005];

bool check(int mpos, int cmp, int r, int l) {
	for (int i = 1; i <= m[mpos] - (l - r); i++) {
		bool tmp = 0;
		for (int j = i; j <= i + (l - r); j++) {
			if (cf[mpos][j] != cf[cmp][j - i + r]) {
				tmp = 1;
				break;
			}
		}
		if (!tmp)
			return 1;
	}
	return 0;
}

void card(int f) {
	for (int r = 1; r <= m[f]; r++) {
		for (int l = m[f]; l >= r; l--) {
			bool tmp = 0;
			for (int j = 1; j <= n; j++) {
				if (j != f && !check(j, f, r, l)) {
					tmp = 1;
					break;
				}
			}
			if (!tmp)
				ans = max(ans, l - r + 1);
		}
	}
}

int main() {
	cin >> n;
	int posminm;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		if (minm > m[i]) {
			minm = m[i];
			posminm = i;
		}
		for (int j = 1; j <= m[i]; j++) {
			int tmp;
			cin >> tmp;
			cf[i][j] = tmp - xl[i];
			xl[i] = tmp;
		}
	}
	card(posminm);
	cout << ans + 1;
}