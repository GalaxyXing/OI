#include<cstdio>
const int rn[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
const int pn[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int Q;
int r;
struct TIME{
    int d,m,y;
};
bool checkrn(int year){
    if(year>1582)return (year%4==0&&year%100!=0||year%400==0);
    else {
        if(year<0)return (year+1)%4==0;
        else return year%4==0;
    }
}
TIME search(int x,TIME start){
    TIME cur=start;
    while(x--){
        cur.d++;
        if(cur.y==1582&&cur.m==10&&cur.d==5)cur.d=15;
        if(checkrn(cur.y)){
            if(cur.d>rn[cur.m])cur.m++,cur.d=1;
        }else if(cur.d>pn[cur.m])cur.m++,cur.d=1;
        if(cur.m>12)cur.y++,cur.m=1;
        if(cur.y==0)cur.y=1;
    }
    return cur;
}
TIME search2(int x){
    TIME tmp={};
    
    if(x>2299604&&x<2305448){
        x-=2299604;
        tmp.d=1,tmp.m=1,tmp.y=1584;
        tmp.y+=(x/1461)*4;
        x%=1461;
        if(x>366){
            tmp.y++;
            x-=366;
            tmp.y+=(x/365);
            tmp=search(x,tmp);
        }
    }


    return tmp;
}
int main(){
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&r);
        TIME tmp;
        if(Q<=1000){            
            tmp=search(r,{1,1,-4713});
        }else{
            tmp=search2(r);
        }        
        printf("%d %d %d %s\n",tmp.d,tmp.m,(tmp.y>0)?tmp.y:-tmp.y,(tmp.y>0)?" ":"BC");
    }
    return 0;
}