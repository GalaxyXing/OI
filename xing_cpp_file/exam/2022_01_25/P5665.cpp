#include<cstdio>
int n;
int a[40000005];
int type,nowcur=1;
long long ans,now,last;
int main(){
    scanf("%d%d",&n,&type);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    now=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>=now){
            ans+=now*now;
            printf("now%lld last%lld\n",now,last);
            last=now;           
            now=a[i];
        }else{
            if(i==n) now+=a[i];
            else if(a[i+1]>now){
                now+=a[i];
            }else{
                if(now>=last){
                    ans+=now*now;
                    printf("anow%lld last%lld\n",now,last);
                    last=now;                   
                    now=a[i]+a[++i];
                }else
                now+= a[i];             
            }
        }
    }
    ans+=now*now;
    printf("%lld",ans);
    return 0;
}