#include<cstdio>
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int fb[5],a,b,flag=1;
        scanf("%d%d",&a,&b);
        if(a==0)printf("0\n");
        else if(b==0)printf("1\n");
        else {
            a%=m,b%=m,fb[0]=a,fb[1]=b,fb[2]=(a+b)%m;
            int cur=2,i=2;
            while(fb[cur]!=0){
                if(fb[cur]==b&&fb[(cur+4)%5]==a){
                    printf("-1\n");
                    flag=0;
                    break;
                }
                i++,cur++;
                fb[cur%5]=(fb[(cur+4)%5]+fb[(cur+3)%5])%m;
                cur%=5;
            }
            if(flag==1)printf("%d\n",i);
        }
    }
    return 0;
}
