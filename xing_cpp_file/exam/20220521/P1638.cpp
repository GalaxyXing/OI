#include<iostream>
using namespace std;
int m,n,draw[1000005],ds[2005],minn=0x7fffffff,cntds,ansr,ansl;
struct DEQUE{
    int l,r,a[1000005];
    void init(){l=1;}
    void push_back(int x){
        a[++r]=x;
    }
    int front(){
    //    if(l>r)return 0;
        return a[l];
    }
    void pop_front(){
       a[ l++]=0;
    }
    int size(){
        return r-l+1;
    }
}win;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>draw[i];
	}
    win.init();
	for(int i=1;i<=n;i++){
		win.push_back(draw[i]);
		if(ds[draw[i]]==0)cntds++;
		ds[draw[i]]++;		
		while(ds[win.front()]>1){
			ds[win.front()]--;
			win.pop_front();
		}
		if(cntds==m){
			if(win.size()<minn){
				minn=win.size();
				ansr=i;
				ansl=i-win.size()+1;
			}
		}
	}
	cout<<ansl<<' '<<ansr<<endl;
	return 0;
}