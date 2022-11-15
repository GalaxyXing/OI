#include <stdio.h>
#include <algorithm>
using namespace std;
int s[10][30] = {}, n[10] = {};
int mintime = 920490545, ltime, rtime, time;
void search(int x, int y) {
	if (y > n[x]) {
		mintime = min(mintime, max(rtime, ltime));
		return ;
	} else {
		ltime += s[x][y];
		search(x, y + 1);
		ltime -= s[x][y];
		rtime += s[x][y];
		search(x, y + 1);
		rtime -= s[x][y];
	}
}
int main() {

	for (int i = 1; i <= 4; i++) {
		scanf("%d", &n[i]);
	}
	for (int i = 1; i <= 4; i++) {
		mintime = 920490545;
		for (int j = 1; j <= n[i]; j++) {
			scanf("%d", &s[i][j]);
		}
		search(i, 1);
		time += mintime;
	}
	printf("%d", time);
	return 0;
}