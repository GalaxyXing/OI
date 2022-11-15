#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int f;
bool tag[10005];
int n;
int s;

int main() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			f = a[i] + a[j];
			//	cout << "f" << f[i] << endl;
			for (int k = j + 1; k <= n; k++) {
				//		cout << 'a' << a[k] << endl;
				if (f == a[k] && !tag[a[k]]) {
					ans++;
					tag[a[k]] = true;
					//	break;
				}
				//	cout << "ans" << ans << endl;
			}
		}
	}
	cout << ans;
	return 0;
}