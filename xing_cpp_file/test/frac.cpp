#include<bits/stdc++.h>
using namespace std;
int a,b,len,last[1005],ans[1005];
struct F{
    int a,b;
    F(int c,int d){int l=__gcd(c,d);a=c/l,b=d/l;}
    F(){a=0,b=1;}
    bool operator==(const F &t)const{return a*t.b==b*t.a;}
    bool operator<(const F &t)const{return a*t.b<b*t.a;}
        bool operator>(const F &t)const{return !(*this<t)&&!(*this==t);}
        bool operator!=(const F &t)const{return !(*this==t);}
        bool operator<=(const F &t)const{return !(*this>t);}
        bool operator>=(const F &t)const{return !(*this<t);}
        F operator-(const F &t)const{int x=a*t.b-t.a*b,y=b*t.b;int l=__gcd(x,y);return F(x/l,y/l);}
        F operator+(const F &t)const{int x=a*t.b+t.a*b,y=b*t.b;int l=__gcd(x,y);return F(x/l,y/l);}
        F operator*(const F &t)const{int x=a*t.a,y=b*t.b,l=__gcd(x,y);return F(x/l,y/l);}
    }x;//�ýṹ��洢���������⾫����
  void dfs(int a,F b,int c,int las){
      if(b>x||c>a)return;//������
      if(c==a){//���ǵ�λ����������10^-7���ڡ����������
          if((x-b).a==1&&(x-b).b<=1e7&&(x-b).b>las){
              if((x-b).b<ans[len]){
                  for(int i=1;i<=len;i++){
                      ans[i]=last[i];
                  }
                  ans[len]=(x-b).b;//���´�
              }
          }
          return;
      }
      for(int i=las+1;i<=ans[len];i++){//ans[len]��Ŀǰ�ġ����Ž⡱���û�����ţ��Ͳ��ü���ö����
          if(F(a-c+1,i)<(x-b))return;
          last[c]=i;
          dfs(a,b+F(1,i),c+1,i);
      }
  }
  int main()
  {
      scanf("%d%d",&a,&b);
      x=F(a,b);
      while(1){
          ans[++len]=INT_MAX;//��ʼΪ����ֵ
          dfs(len,F(0,1),1,0);
          if(ans[len]!=INT_MAX){//�н���
              for(int i=1;i<=len;i++)printf("%d ",ans[i]);//���
              break;
          }
      }
      return 0;
  }