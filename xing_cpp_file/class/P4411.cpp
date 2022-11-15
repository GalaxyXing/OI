#include <iostream>
#include <algorithm>

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
#define LL long long
#define MAXN 50020
int N;
int L;
LL dp[MAXN];
int a[MAXN];
using namespace std;

int main() {
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	dp[1]=1;
	for(int i=1;i<=N;i++){
		dp[i]
	}
	return 0;
}