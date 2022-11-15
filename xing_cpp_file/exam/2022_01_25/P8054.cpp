#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        unsigned long long tmp;
        scanf("%llu",&tmp);
        bool flag=1;
        int cnt3=0;
        unsigned long long cnt=0;
        unsigned long long cmp=tmp;
        for(int i=2;i<=tmp;i++){
            while(tmp%i==0){
                tmp/=i;
                if(i==3)cnt3++;
                if(cnt3>1){
                    i=10;
                    break;
                }
            }
            if(i>4){
                printf("1\n");
                flag=0;
                break;
            }
        }
        if(flag)printf("0\n");
    }
    return 0;
}