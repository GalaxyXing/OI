#include <set>
#include <iostream>
using namespace std;
multiset<int>tree;
multiset<int>::iterator iter1, iter2;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp, cz;
		cin >> cz >> tmp;
		if (cz == 1) {
			iter1 = tree.lower_bound(tmp);
			iter2 = tree.begin();
			int cnt = 1;
			while (iter2 != iter1) {
				iter2++;
				cnt++;
			}
			cout << cnt << endl;
		} else if (cz == 5) {
			tree.insert(tmp);
		} else if (cz == 2) {
			iter1 = tree.begin();
			while (tmp - 1) {
				tmp--;
				iter1++;
			}
			cout << *iter1 << endl;
		} else if (cz == 3) {
			iter1 = tree.lower_bound(tmp);
			if (iter1 == tree.begin())
				cout << -2147483647 << endl;
			else {
				iter1--;
				cout << *iter1 << endl;
			}
		} else if (cz == 4) {
			iter1 = tree.upper_bound(tmp);
			if (iter1 == tree.end())
				cout << 2147483647 << endl;
			else
				cout << *iter1 << endl;
		}
	}
	return 0;
}