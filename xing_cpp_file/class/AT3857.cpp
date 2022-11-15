#include<cstdio>
#include<bitset>
int n;
std::bitset<5000000> bit;
int all;
int main(){
    bit[0]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        bit|=(bit<<tmp);
        all+=tmp;
    }
    for(int i=(all+1)>>1;i<=all;i++){
        if(bit[i]){
            return printf("%d",i),0;
}
    }
}