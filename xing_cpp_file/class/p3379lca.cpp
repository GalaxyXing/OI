#include <iostream>
#include <algorithm>
using namespace std;
int N, M, S;
const int MAXn = 5e5 + 10;

struct edge {
	int next, to;
} tree[2 * MAXn];
int dep[MAXn], fa[MAXn][22], head[MAXn], cnt;

void add(int u, int v) {
	cnt++;
	tree[cnt].to = v;
	tree[cnt].next = head[u];
	head[u] = cnt;
}//创建边，head[u]为u点上引出的当前边号次大的边，cnt为边号
//cnt(0)为无边(即每个head[u]初始所指向的边号），即搜索跳出条件
//tree[cnt].to为该边（cnt）所指向的点v;
//tree[cnt].next为第cnt条边指向的下一条应指向的边，即原head[u]边
//head[u]更新为当前边号（此时head[u]为u点上引出的边号最大的边即cnt）

void dfs(int son, int f) {
	dep[son] = dep[f] + 1;
	fa[son][0] = f;
	for (int i = 1; (1 << i) <= dep[son]; i++) {
		fa[son][i] = fa[fa[son][i - 1]][i - 1];
	}
	for (int i = head[son]; i; i = tree[i].next) {
		if (tree[i].to != f)
			dfs(tree[i].to, son);
	}
//生成树，其中son为子节点（现在正在搜索的）
//fa为父节点（由于生成的无向图，所以为了防止son又搜回fa，要加一个特判）
//tree[i].to为son的子节点即下一个递归所应搜索的节点，i为从u出发的边的边号
}

int lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v); //始终保持u的深度比v大
	for (int i = 20; i + 1 ; i--) {
		if (dep[v] <= dep[u] - (1 << i))
			u = fa[u][i];//利用倍增提高u使得u和v一样浅
	}
//	cout << "深度v，u" << v << ' ' << dep[v] << ' ' << u << ' ' << dep[u] << endl;
	if (u == v)
		return u;//如果v是u的祖先，直接输出（深度一样且为同一个节点）

	for (int i = 20; i + 1; i--) {
		if (fa[u][i] != fa[v][i])//不等于时，其祖先才在其更浅的地方
			u = fa[u][i], v = fa[v][i];//利用倍增同时对u，v进行递增
		else
			continue;
	}
	//最后则fa[u][0]才与fa[v][0]相等，即找到了提高后的u节点，v节点的父节点
	//即u,v的最近公共祖先
	return fa[u][0];
}

int main() {
	cin >> N >> M >> S;
	for (int i = 1; i < N; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		add(tmp1, tmp2);//把tmp1-tmp2边放进图中
		add(tmp2, tmp1);//把tmp2-tmp1边放进图中
		//因为tmp1和tmp2之间的边没有方向，所以可能有两种情况
	}
	dfs(S, 0);
	for (int i = 1; i <= M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		cout << lca(tmp1, tmp2) << endl;
	}
	return 0;
}