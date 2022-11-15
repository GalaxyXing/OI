#include<iostream>
#include<cmath>
using namespace std;
double a,b,d;
const double pi=acos(-1);
int main(){
    cin>>a>>b>>d;
    bool zheng=0;
    double basic=0;
    double length=sqrt(a*a+b*b);
    if(length==0.0){
        cout<<0<<' '<<0<<endl;
        return 0;
    }
    if(a>0&&b>0)basic=0;
    else if(b==0&&a>0)basic=0,zheng=1;
    else if(a<0&&b>0)basic=180;
    else if(a==0&&b>0)basic=90,zheng=1;
    else if(a<0&&b<0)basic=180;
    else if(b==0&&a<0)basic=180,zheng=1;
    else if(a>0&&b<0)basic=360;
    else if(a==0&&b<0)basic=270,zheng=1;
    double deg=0;
    if(!zheng){
    //    cout<<(abs(a)/length)<<endl;
        if(a*b>0)deg=acos(abs(a)/length);
        else deg=-acos(abs(a)/length);
        deg+=basic/180.0*pi;
    }else deg=basic/180.0*pi;
    double e=pi*d/180.0;
    double dd=deg+e;
    double oa=length*cos(dd);
    double ob=length*sin(dd);
    printf("%.10lf %.10lf",oa,ob);
    return 0;
}