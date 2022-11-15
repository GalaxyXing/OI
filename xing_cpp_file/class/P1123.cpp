#include <iostream>
#include <algorithm>
using namespace std;
int n, m ;
int map[10][10];
bool mapb[10][10];
int maxx, ans;

void flag(int a, int b, bool c) {
	for (int i = a - 1; i <= a + 1; i++) {
		for (int j = b - 1; j <= b + 1; j++) {
			mapb[i][j] = c;
		}
	}
}

void  dfs(int x, int y) {
	if (x > n) {
		maxx = max(maxx, ans);
//		cout << maxx << endl;
		return ;
	} else if (y > m) {
		dfs(x + 1, 1);
	} else {
		if (!mapb[x][y]) {
			ans += map[x][y];
			cout << ans << '+' << endl;
			flag(x, y, true);
			dfs(x, y + 1);
			ans -= map[x][y];
			cout << ans << '-' << endl;
			flag(x, y, false);
		}
		dfs(x, y + 1);
	}
}

int main() {
	int T;
	cin >> T;
	for (int q = 0; q < T; q++) {
		cin >> n >> m;
		maxx = 0;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				map[i][j] = 0;
				mapb[i][j] = false;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
			}
		}
		dfs(1, 1);
		cout << maxx << endl;
	}
}