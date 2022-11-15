#include <queue>
#include <cstdio>
#include <vector>
#define MAXE 2005
#define MAXK 60
#define MAXN 1005
#define INF 0x7fffffffffffffff
using namespace std;

struct EDGE {
	int next, to;
	double val;
} e[MAXE * MAXK * 4];

struct NODE {
	double dis;
	int pos;
	bool operator<(const NODE &x)const {
		return x.dis < dis;
	}
};
priority_queue<NODE>pq;
vector<NODE>crs_fl;//cross floor
int n, m, k, T, head[MAXN * MAXK], cnt;
double dis[MAXN * MAXK];

bool vis[MAXN * MAXK] = {};

inline void addedge(int u, int v, double w) {
	e[++cnt].next = head[u], e[cnt].val = w, e[cnt].to = v, head[u] = cnt;
}

double DJ(int s) {
	for (int i = 1; i <= n * (k + 1); i++)
		dis[i] = INF, vis[i] = 0;
	dis[s] = 0;
	pq.push(NODE{dis[s], s});
	while (!pq.empty()) {
		NODE cur = pq.top();
		pq.pop();
		int tmp = cur.pos;
		if (vis[tmp] == 1)
			continue;
		vis[tmp] = 1;
		for (int i = head[tmp]; i; i = e[i].next) {
			if (dis[e[i].to] > dis[tmp] + e[i].val) {
				dis[e[i].to] = dis[tmp] + e[i].val;
				if (vis[e[i].to] == 0)
					pq.push(NODE{dis[e[i].to], e[i].to});
			}
		}
	}
	return dis[n * (k + 1)];
}

double check(double x) {
	if (x == 0) {
		int size = crs_fl.size();
		for (int i = 0; i < size; i++)
			e[crs_fl[i].pos].val = 0;
		double ans = DJ(1);
		for (int i = 0; i < size; i++)
			e[crs_fl[i].pos].val = crs_fl[i].dis;
		return ans;
	} else {
		int size = crs_fl.size();
		for (int i = 0; i < size; i++)
			e[crs_fl[i].pos].val /= x;
		double ans = DJ(1);
		for (int i = 0; i < size; i++)
			e[crs_fl[i].pos].val *= x;
		return ans;
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &T);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		for (int j = 0; j <= k; j++) {
			addedge(u + j * n, v + j * n, (double)w);
			addedge(v + j * n, u + j * n, (double)w);
		}
		for (int j = 1; j <= k; j++) {
			addedge(u + (j - 1)*n, v + j * n, (double)w);
			crs_fl.push_back({(double)w, cnt});
			addedge(v + (j - 1)*n, u + j * n, (double)w);
			crs_fl.push_back({(double)w, cnt});
		}
	}
	double l = 1, r = 1000000, ans = check(0);
	if (ans > T) {
		printf("gg\n%.0lf", ans);
		return 0;
	}
	while (r - l > 0.0001) {
		double mid = (r + l) / 2;
		double tmp = check(mid);
		if (tmp < T)
			r = mid;
		else if (tmp > T)
			l = mid;
		else {
			printf("%.3lf", mid);
			return 0;
		}
	}
	if (check(r) <= T)
		ans = r;
	if (check((r + l) / 2) <= T)
		ans = (r + l) / 2;
	if (check(l) <= T)
		ans = l;
	printf("%.3lf", ans);
	return 0;
}