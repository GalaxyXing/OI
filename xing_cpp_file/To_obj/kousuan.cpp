#include <stdio.h>
#include <time.h>
#include <stdlib.h>
bool vis[30005][30005][2], flag[1000005];
int n, mod;
time_t timer;
tm *now;
int main() {
	time(&timer);
	now = localtime(&timer);
	srand(timer);
	printf("\\|| ���� || ���� || ������||//\n\t ||������||\n������Ҫ������ʽ�������1000000����\n");
	scanf("%d", &n);
	if (n > 1000000 || n < 1) {
		printf("ERROR\n");
		system("pause");
		return 0;
	}
	printf("������ҪҪ�������ڵļӼ����������30000���ڣ�\n");
	scanf("%d", &mod);
	if (mod > 30000 || mod < 2) {
		printf("ERROR\n");
		system("pause");
		return 0;
	}
	printf("����ͬĿ¼���С�����.doc�������ɵ���ʽ\n���뽫�ֺŵ�ΪС�ĺ�\n");
	system("pause");
	freopen("����.doc", "w", stdout);
	printf("\t\t%d%d%d\t\t%02d:%02d:%02d\t\n", (now->tm_hour) + 2001, ( now->tm_mon ) + 1, now->tm_mday, now->tm_hour,now->tm_min, now->tm_sec);
	for (int i = 1; i <= n; i++) {
		int tmp1 = rand() % mod,tmp2 = rand() % mod,tmp3 = rand() % 2;
		if (tmp3)
			if (tmp1 + tmp2 <= mod)
				if (!vis[tmp1][tmp2][tmp3]) {
					printf("%5d+%5d=    ", tmp1, tmp2);
					vis[tmp1][tmp2][tmp3] = 1;
				} else
					i--;
			else
				i--;
		else {
			if (tmp1 > tmp2)
				if (!vis[tmp1][tmp2][tmp3]) {
					printf("%5d-%5d=    ", tmp1, tmp2);
					vis[tmp1][tmp2][tmp3] = 1;
				} else
					i--;
			else if (!vis[tmp2][tmp1][tmp3]) {
				printf("%5d-%5d=    ", tmp2, tmp1);
				vis[tmp2][tmp1][tmp3] = 1;
			} else
				i--;
		}
		if ((!(i % 4)) && (!flag[i])) {
			flag[i] = 1;
			printf("\n");
		}
	}
	return 0;
}