#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int cxj[100005],gxj[100005];
bool check(int x){
    int l=1,r=m+1,mid;
    while(r-l>1)mid=l+r>>1,(gxj[mid]>x)?r=mid:l=mid;
    return gxj[l]==x;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",cxj+i);    
    for(int i=1;i<=m;i++) scanf("%d",gxj+i);    
    sort(gxj+1,gxj+1+m);
    for(int i=1;i<=n;i++)check(cxj[i])?printf("%d ",cxj[i]):0;    
    return 0;
}
