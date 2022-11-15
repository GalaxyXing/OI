#include<bits/stdc++.h>

using namespace std;

const int N = 205;

int n;
int color[N], num[N], suf[N], f[N][N][N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        cin >> color[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= n; i++){   //预处理出 suf[i]
        for(int j = i + 1; j <= n; j++){
            if(color[i] == color[j]){
                suf[i] += num[j];
            }
        }
    }
    memset(f, 0xcf, sizeof(f));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= suf[i]; j++){
            f[i][i][j] = (num[i] + j) * (num[i] + j);   //这里预处理出 f 数组
        }
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            for(int k = 0; k <= suf[j]; k++){   //注意：0 也可以
                f[i][j][k] = max(f[i][j][k], f[i][j - 1][0] + (num[j] + k) * (num[j] + k));
            }
            for(int k = i; k <= j - 2; k++){   //这里为什么 j - 1 不行，因为要删掉 k + 1 到 j - 1 的，而 k = j - 1 是无效的
                if(color[k] == color[j]){
                    for(int t = 0; t <= suf[j]; t++){
                        f[i][j][t] = max(f[i][j][t], f[i][k][num[j] + t] + f[k + 1][j - 1][0]);    //这里为什么是 num[j] + t，因为 k 和 j 合并了，所以 j 后面一共有 num[j] + t 个
                    }
                }
            }
        }
    }
    printf("%d\n", f[1][n][0]);
	return 0;
}   