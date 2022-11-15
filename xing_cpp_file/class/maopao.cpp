//ц╟ещ

int a[10] = {3, 5, 2, 99, 55, 6, 7,  456, 77, 10};
#include <stdio.h>

int main() {
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}