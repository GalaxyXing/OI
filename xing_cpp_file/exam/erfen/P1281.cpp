#include<cstdio>
int book[505],k,m,cntbook,maxbook;
struct PERSON{
    int from,to;
}person[505];
int max(int x,int y){return (x>y)?x:y;}
bool check(int x){
    int all=0,cnt=1,person_cur=k,book_cur;
    PERSON person_tmp={m,m};
    for(int i=1;i<=k;i++)person[i]=(PERSON){0,0};
    for(book_cur=m;book_cur>=1;book_cur--){
        if(all+book[book_cur]>x){
            person[person_cur]=person_tmp;
            person_tmp=(PERSON){book_cur,book_cur};
            all=book[book_cur],person_cur--;
        }
        else {
            person_tmp.from=book_cur;
            all+=book[book_cur];
        }
        if(person_cur<=0)return 0;
    }
    person[person_cur]=person_tmp;
    return 1;
}
void output(int x){
    check(x);
    for(int i=1;i<=k;i++)
    printf("%d %d\n",person[i].from,person[i].to);    
}
int main(){
    scanf("%d%d",&m,&k);
    for(int i=1;i<=m;i++)scanf("%d",book+i),cntbook+=book[i],maxbook=max(maxbook,book[i]);
    int l=max(cntbook/m,maxbook)-10,r=cntbook+10,mid;
    while(r-l>1)mid=l+r>>1,(check(mid)?r=mid:l=mid);
    output(r);
    return 0;  
}