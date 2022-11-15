#include <stdio.h>

int main() {
	int a, b;
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	scanf("%d %d", &a, &b);
	printf("%d %d\n", b, a);
//	fclose("1.in");
//	fclose("2.out");
	printf("%d %d", a, b);
	return 0;
}