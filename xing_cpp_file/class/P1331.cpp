#include <iostream>
#include <algorithm>
using namespace std;
int ship[1005][1005];
int s;
bool flag[1005][1005];
int r, c;

bool check0(int x, int y) {
	if (!flag[x][y - 1] && !flag[x - 1][y])
		return true;
	else
		return false;
}

bool check1(int x, int y) {
	if (flag[x][y - 1] && flag[x - 1][y] && !flag[x - 1][y - 1])
		return true;
	if (flag[x][y - 1] && flag[x + 1][y] && !flag[x + 1][y - 1])
		return true;
	if (flag[x][y + 1] && flag[x - 1][y] && !flag[x - 1][y + 1])
		return true;
	if (flag[x][y + 1] && flag[x + 1][y] && !flag[x + 1][y + 1])
		return true;
	else
		return false;
}

void dfs(int x, int y) {
	if (x > r)
		return ;
	else if (y > c)
		dfs(x + 1, 1);
	else {
		if (flag[x][y]) {
			if (check1(x, y)) {
				s = -1;
				return;
			} else if (check0(x, y)) {
				s++;
				ship[x][y] = s;
			} else {
				if (flag[x - 1][y])
					ship[x][y] = ship[x - 1][y];
				else if (flag[x][y - 1])
					ship[x][y] = ship[x][y - 1];
			}
		}
		dfs(x, y + 1);
	}
}
int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char temp;
			cin >> temp;
			if (temp == '#')
				flag[i][j] = true;
		}
	}
	dfs(1, 1);
	if (s >= 0)
		cout << "There are " << s << " ships.";
	else
		cout << "Bad placement.";
	return 0;
}