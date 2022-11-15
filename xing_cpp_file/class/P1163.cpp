#include"cstdio"
#include"cmath"
double All,PerMonth,Month;
double Rate;
bool check(double x){
    return (pow(1.0+x/100,-Month)>=1.0-All/PerMonth*(x/100.0));
}
int main(){
    scanf("%lf%lf%lf",&All,&PerMonth,&Month);
    double l=0,r=100000,mid;
    while(r-l>0.05)mid=(l+r)/2,(check(mid))?r=mid:l=mid;
    printf("%.1lf",l);
    return 0;
}