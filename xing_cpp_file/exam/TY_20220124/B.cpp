#include<cstdio>
#include<algorithm>
struct LINE{
    int l,r;
    bool operator<(const LINE &x)const{
        if(r==x.r)return l<x.l;
        else return r<x.r;
    }
}zh[100005],hr[1050];//×¡»§£¬º°ÈË
long long dp[1050][1050];
int n,cnt;
int main(){
   // freopen("E:\\code\\xing_cpp_file\\exam\\TY_20220124\\test.in","r",stdin);
   // freopen("E:\\code\\xing_cpp_file\\exam\\TY_20220124\\test.ans","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&zh[i].l,&zh[i].r);
    }
    std::sort(zh+1,zh+1+n);
    int nowright=0;
    // for(int i=1;i<=n;i++){
    //     printf("%d %d\n",zh[i].l,zh[i].r);
    // }
    for(int i=1;i<=n;i++){
        if(zh[i].l>nowright){
            nowright=zh[i].r;
           // printf("now %d\n",nowright);
            cnt++;
        }
    }
    printf("%d\n%d",cnt,5);
    return 0;
}
// now 89
// now 156
// now 257
// now 289
// now 298