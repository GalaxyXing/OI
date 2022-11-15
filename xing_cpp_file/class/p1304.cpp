#include <stdio.h>

int main() {
	int n, p, q;
	bool flag[20008] = {};
	scanf("%d", &n);
	for (int i = 4; i <= n; i += 2) {
		for (int j = 2; j <= i / 2; j++) {
			if (!flag[j]) {
				for (int k = 2; k <= n / j ; k++) {
					flag[j * k] = true;
				}
				q = i - j;
				p = j;
				if (!flag[q])
					break;
			}
		}
		printf("%d=%d+%d\n", i, p, q);
	}
	return 0;
}