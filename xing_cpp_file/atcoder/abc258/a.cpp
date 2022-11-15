#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int hh=21,mm=0;
    hh+=n/60;
    mm+=n%60;
    printf("%02d:%02d",hh,mm);
    return 0;
}