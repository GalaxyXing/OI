#include<cstdio>
int n,m;
int a[1000006];
int findd(int x){
    int l=0,r=n,mid;
    while(r-l>1)mid=(l+r)>>1,(a[mid]<x)?l=mid:r=mid;
    return (a[r]==x)?r:-1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    while(m--){
        int tmp;
        scanf("%d",&tmp);
        printf("%d ",findd(tmp));   
    }
    return 0;
}