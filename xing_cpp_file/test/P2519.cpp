#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read() {
    int res = 0; bool bo = 0; char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-');
    if (c == '-') bo = 1; else res = c - 48;
    while ((c = getchar()) >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - 48);
    return bo ? ~res + 1 : res;
}
const int N = 1e5 + 5;
int n, tn, f[N];
struct cyx {
    int l, r, v;
} a[N], b[N];
bool comp1(cyx a, cyx b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}
bool comp2(cyx a, cyx b) {
    if (a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}
int findx(int l, int r, int val) {
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid].r < val) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main() {
	freopen("E:/code/xing_cpp_file/dp.in","r",stdin);
	freopen("E:/code/xing_cpp_file/dp.ans","w",stdout);
    int i, x, y, tmpn; tmpn = read();
    for (i = 1; i <= tmpn; i++) a[i].l = read() + 1, a[i].r = tmpn - read();
    sort(a + 1, a + tmpn + 1, comp1);
    for (i = 1; i <= tmpn; i++) if (a[i].l <= a[i].r) b[++tn] = a[i];
    for (i = 1; i <= tn; i++) if (i == 1 || b[i].l != b[i - 1].l ||
        b[i].r != b[i - 1].r) a[++n] = b[i], a[n].v = 1;
        else if (a[n].v < a[n].r - a[n].l + 1) a[n].v++;
    sort(a + 1, a + n + 1, comp2); f[1] = a[1].v;
    for (i = 2; i <= n; i++) {
        int nxt = findx(1, i - 1, a[i].l);
        f[i] = max(f[i - 1], f[nxt] + a[i].v);
    }
    cout << tmpn - f[n] << endl;
    return 0;
}