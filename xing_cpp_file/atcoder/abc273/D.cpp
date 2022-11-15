#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int h,w,n,q;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//0 右 1下 2 左 3 上
struct Pos{
    int x,y;
    bool operator==(const Pos &t)const{
        return x==t.x&&y==t.y;
    }
}st,wwall[200005],hwall[200005],rwwall[200005],rhwall[200005];
bool find1(Pos x,Pos y){
    return x.x<y.x;
}
bool find2(Pos x,Pos y){
    return x.y<y.y;
}
bool find3(Pos x,Pos y){
    return x.y>y.y;
}
bool find4(Pos x,Pos y){
    return x.x>y.x;
}
void check(Pos &v,Pos u,int di){
    if(di==0||di==2){
        int pos=std::lower_bound(wwall+1,wwall+1+n,u,find1)-wwall;        
        if(wwall[pos].x!=v.x||pos==n+1)return;
        int lpos=std::upper_bound(wwall+1,wwall+1+n,u,find1)-wwall;
        if(di==0){
            pos=std::lower_bound(wwall+pos,wwall+lpos,u,find2)-wwall;     
            if(pos==lpos||wwall[pos].y>v.y)return;
            v.y=wwall[pos].y-1;
        }else{
            pos=std::lower_bound(rwwall+pos,rwwall+lpos,u,find3)-rwwall;
            if(pos==lpos||rwwall[pos].y<v.y)return;
            v.y=wwall[pos].y+1;
        }
    }else if(di==1||di==3){
        int pos=std::lower_bound(hwall+1,hwall+1+n,u,find2)-hwall;
        if(hwall[pos].y!=v.y||pos==n+1)return;
        int lpos=std::upper_bound(hwall+1,hwall+1+n,u,find2)-hwall;
        if(di==1){
            pos=std::lower_bound(hwall+pos,hwall+lpos,u,find1)-hwall;
            if(pos==lpos||hwall[pos].x>v.x)return;
            v.x=hwall[pos].x-1;
        }else{
            pos=std::lower_bound(rhwall+pos,rhwall+lpos,u,find4)-rhwall;
            if(pos==lpos||rhwall[pos].x<v.x)return;
            v.x=rhwall[pos].x+1;
        }
        
    }
}
void mov(int di,int x){
    Pos tmp=st;
    st.x+=dx[di]*x;
    st.y+=dy[di]*x;
    if(st.x<1)st.x=1;
    else if(st.x>h)st.x=h;
    if(st.y<1)st.y=1;
    else if(st.y>w)st.y=w;
    if(st==tmp)return;
    check(st,tmp,di);
    return;
}
bool cmp1(Pos x,Pos y){
    return (x.x==y.x)?x.y<y.y:x.x<y.x;
}
bool cmp2(Pos x,Pos y){
    return (x.y==y.y)?x.x<y.x:x.y<y.y;
}
bool cmp3(Pos x,Pos y){
    return (x.x==y.x)?x.y>y.y:x.x<y.x;
}
bool cmp4(Pos x,Pos y){
    return (x.y==y.y)?x.x>y.x:x.y<y.y;
}
int main(){
    #ifdef LOCAL
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>h>>w>>st.x>>st.y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>wwall[i].x>>wwall[i].y;
        rhwall[i]=rwwall[i]=hwall[i]=wwall[i];
    }
    std::sort(wwall+1,wwall+1+n,cmp1);
    std::sort(hwall+1,hwall+n+1,cmp2);
    std::sort(rwwall+1,rwwall+1+n,cmp3);
    std::sort(rhwall+1,rhwall+1+n,cmp4);
    // for(int i=1;i<=n;i++){
    //     cout<<wall[i].x<<" "<<wall[i].y<<endl;
    // }
    cin>>q;
    while(q--){
        char d;
        int l,di;
        cin>>d>>l;
        if(d=='R')di=0;
        else if(d=='U')di=3;
        else if(d=='L')di=2;
        else di=1;
        mov(di,l);
        cout<<st.x<<" "<<st.y<<endl;
    }
    return 0;
}