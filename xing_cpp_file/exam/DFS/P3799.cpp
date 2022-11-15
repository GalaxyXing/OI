#include<cstdio>
int a,cnt[5005],maxx,n,ans;
const int MOD=1e9+7;

inline int C(int x, int y) {
    return (y==1)?x: x*(x-1)/2%MOD;
}

inline int max(int x, int y) {
    return x>y?x: y;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)scanf("%d", &a),
    cnt[a]++,
    maxx=max(maxx, a);

    for(int i=1; i<=maxx; i++) {
        if(cnt[i]<2)continue;

        else {
            int anst=0;

            for(int j=1; j<=i/2; j++) {
                if(cnt[j]>=1&&i-j>j&&cnt[i-j]>=1)anst+=C(cnt[j], 1)*C(cnt[i-j], 1),
                anst%=MOD;
                else if(cnt[j]>=2&&i==(j<<1))anst+=C(cnt[j], 2),
                anst%=MOD;
            }

            anst*=C(cnt[i], 2),
            anst%=MOD;
            ans+=anst,
            ans%=MOD;
        }
    }

    printf("%d", ans);
    return 0;
}