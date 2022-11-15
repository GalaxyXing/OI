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
}//�����ߣ�head[u]Ϊu���������ĵ�ǰ�ߺŴδ�ıߣ�cntΪ�ߺ�
//cnt(0)Ϊ�ޱ�(��ÿ��head[u]��ʼ��ָ��ıߺţ�����������������
//tree[cnt].toΪ�ñߣ�cnt����ָ��ĵ�v;
//tree[cnt].nextΪ��cnt����ָ�����һ��Ӧָ��ıߣ���ԭhead[u]��
//head[u]����Ϊ��ǰ�ߺţ���ʱhead[u]Ϊu���������ıߺ����ı߼�cnt��

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
//������������sonΪ�ӽڵ㣨�������������ģ�
//faΪ���ڵ㣨�������ɵ�����ͼ������Ϊ�˷�ֹson���ѻ�fa��Ҫ��һ�����У�
//tree[i].toΪson���ӽڵ㼴��һ���ݹ���Ӧ�����Ľڵ㣬iΪ��u�����ıߵıߺ�
}

int lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v); //ʼ�ձ���u����ȱ�v��
	for (int i = 20; i + 1 ; i--) {
		if (dep[v] <= dep[u] - (1 << i))
			u = fa[u][i];//���ñ������uʹ��u��vһ��ǳ
	}
//	cout << "���v��u" << v << ' ' << dep[v] << ' ' << u << ' ' << dep[u] << endl;
	if (u == v)
		return u;//���v��u�����ȣ�ֱ����������һ����Ϊͬһ���ڵ㣩

	for (int i = 20; i + 1; i--) {
		if (fa[u][i] != fa[v][i])//������ʱ�������Ȳ������ǳ�ĵط�
			u = fa[u][i], v = fa[v][i];//���ñ���ͬʱ��u��v���е���
		else
			continue;
	}
	//�����fa[u][0]����fa[v][0]��ȣ����ҵ�����ߺ��u�ڵ㣬v�ڵ�ĸ��ڵ�
	//��u,v�������������
	return fa[u][0];
}

int main() {
	cin >> N >> M >> S;
	for (int i = 1; i < N; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		add(tmp1, tmp2);//��tmp1-tmp2�߷Ž�ͼ��
		add(tmp2, tmp1);//��tmp2-tmp1�߷Ž�ͼ��
		//��Ϊtmp1��tmp2֮��ı�û�з������Կ������������
	}
	dfs(S, 0);
	for (int i = 1; i <= M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		cout << lca(tmp1, tmp2) << endl;
	}
	return 0;
}