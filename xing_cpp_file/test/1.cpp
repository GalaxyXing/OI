// 线段树要开4倍空间
#include <stdio.h>
#define Maxn 100005
#define LL long long 
#define lc(p) p<<1
#define rc(p) (p<<1)+1

LL a[Maxn],t[Maxn<<2],tag[Maxn<<2];
void push(int p){t[p]=t[lc(p)]+t[rc(p)];}
void build(int p,int l,int r){
	if(l==r){t[p]=a[l];return;}
	int mid=l+r>>1;
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
	push(p);
}
void add(int p,int l,int r,LL k)
{
	tag[p]+=k;
	t[p]+=(r-l+1)*k;	
} 
void push_down(int p,int l,int r)
{
	if(tag[p])
	{
		int mid=l+r>>1;
		add(lc(p),l,mid,tag[p]);
		add(rc(p),mid+1,r,tag[p]);
		tag[p]=0;
	}
}
void modify(int p,int l,int r,int ul,int ur,LL k){
	if(ul<=l&&r<=ur){add(p,l,r,k);return;}
	push_down(p,l,r);
	int mid=l+r>>1;
	if(ul<=mid) modify(lc(p),l,mid,ul,ur,k);
	if(ur>mid) modify(rc(p),mid+1,r,ul,ur,k);
	push(p); 
}
LL query(int p,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr){return t[p];}
	LL tot=0;
	int mid=l+r>>1;
	push_down(p,l,r);
	if(ql<=mid) tot+=query(lc(p),l,mid,ql,qr);
	if(qr>mid) tot+=query(rc(p),mid+1,r,ql,qr); 
	return tot;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int l,r,opt;
        int k;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%lld",&l,&r,&k);
			modify(1,1,n,l,r,k);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,1,n,l,r));
		}
		
	}	
	return 0; 
}