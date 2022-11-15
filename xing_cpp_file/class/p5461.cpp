#include <stdio.h>
#include <math.h>
int n;
bool fz[2000][2000];

void sm(int x, int y,int xx,int yy) {
	if (xx > n||yy>n)
		fz[pow(2,xx-1)][pow(2,yy-1)]=true;
		return ;
	else {		
		xx++;
		sm(x+1,y+1,xx,yy);
		yy++;
		sm(x+1,y+1,xx,yy);
		xx--;
		sm(x+1,y+1,xx,yy);
		yy--;
	}
}

int main() {
	scanf("%d", &n);
	sm(0,0,0,0);//Ω¯––…‚√‚
}