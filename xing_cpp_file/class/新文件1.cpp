
#include <cstdio>
using namespace std;
bool isok[10001005];
long long num[2000005], n, maxn;
long long next[10001005], last;

long long max(long long x, long long y) {
	return ((x > y) ? x : y);
}

void pre(long long x) {
	for (long long i = 1; i <= x; i++) {
		if (isok[i] == false) {
			long long tmp = i;
			while (tmp) {
				if (tmp % 10 == 7) {
					isok[i] = true;
					for (long long j = 2; j * i <= x; j++) {
						isok[j * i] = true;
					}
					break;
				} else
					tmp /= 10;
			}
		}
		if (isok[i] == false) {
			next[last] = i;
			last = i;
		}
	}
}

int main() {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &num[i]);
		maxn = max(maxn, num[i]);
	}
	pre(maxn + 1000);
	for (long long i = 1; i <= n; i++) {
		if (isok[num[i]]) {
			printf("-1\n");
		} else
			printf("%lld\n", next[num[i]]);
	}
	return 0;
}