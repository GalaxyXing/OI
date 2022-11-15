#include <stdio.h>

int a[10] = {9, 5, 4, 11, 2, 5, 99, 76, 56, 11};

int main() {
	for (int i = 0; i < 10; i++) {
		int max = a[i];
		int isp = i;
		for (int j = i; j < 10; j++) {
			if (a[j] > max) {
				max = a[j];
				isp = j;
			}
		}
		a[isp] = a[i];
		a[i] = max;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}