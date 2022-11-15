#include <stdio.h>
int a, b;

void s() {
	int temp;
	temp = b;
	b = a;
	a = temp;
	return;
}

int main() {

	scanf("%d%d", &a, &b);
	s();
	printf("%d %d", a, b);
	return 0;
}