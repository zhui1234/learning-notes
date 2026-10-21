#include<iostream>
#include<cstdio>
using namespace std;

int dx[8]={-1,-1,1,1,-2,-2,2,2};
int dy[8]={-2,2,-2,2,-1,1,-1,1};

int x1,y1,x2,y2;
unsigned long long ans[30][30];
bool p[30][30];
bool pd(int x,int y)
{
	return x>0 && x<=x1 && y>0 && y<=y1;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	x1++,y1++,x2++,y2++;
	p[x2][y2]=1;
	for(int i=0;i<8;i++)
		if(pd(x2+dx[i],y2+dy[i]))
			p[x2+dx[i]][y2+dy[i]]=1;
	ans[1][1]=1;
	for(int i=1;i<=x1;i++)
		for(int j=1;j<=y1;j++)
			if(!p[i][j])
				ans[i][j]+=ans[i-1][j]+ans[i][j-1];
	printf("%lld",ans[x1][y1]);
	return 0;
} 
