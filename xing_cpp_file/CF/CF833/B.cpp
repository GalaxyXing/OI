#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
unsigned char tong[105][11];
char s[100005];
int len;
void solve(){
    scanf("%d",&len);
    scanf("%s",s+1);
    memset(tong,0,sizeof(tong));
    long long ans=0;
    for(int r=1;r<=std::min(100,len);r++){
        for(int j=0;j<=10;j++){
            tong[r][j]=tong[r-1][j];
        }
        tong[r][s[r]-'0']++;
        if(tong[r][s[r]-'0']==1)tong[r][10]++;
    }
    for(int i=1;i<=len;i++){
        for(int le=1,r=i+le-1;r<=len&&le<=100;le++,r++){
            if(i!=1){
                tong[le][s[r]-'0']++;
                if(tong[le][s[r]-'0']==1)tong[le][10]++;
                // printf("a i %d le %d 10 %d\t",i,le,tong[le][10]);
                tong[le][s[i-1]-'0']--;
                if(tong[le][s[i-1]-'0']==0)tong[le][10]--;
                // printf("b i %d le %d 10 %d\n",i,le,tong[le][10]);
            }
            unsigned char flag=1;
            for(int j=0;j<=9;j++){
                // printf("c i %d le %d 10 %d\t",i,le,tong[le][10]);
                // printf("c i %d le %d %d %d\n",i,le,j,tong[le][j]);
                if(tong[le][j]>tong[le][10]){
                    flag=0;
                    break;
                }
            }
            ans+=flag;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}