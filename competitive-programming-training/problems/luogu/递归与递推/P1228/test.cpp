#include<iostream>
#include<cstdio>
using namespace std;

bool p[1100][1100];
void Print(int x,int y)
{
	if(p[x][y]){printf("%d %d 1\n",x+1,y+1);return;}
	if(p[x][y+1]){printf("%d %d 2\n",x+1,y);return;}
	if(p[x+1][y]){printf("%d %d 3\n",x,y+1);return;}
	if(p[x+1][y+1]){printf("%d %d 4\n",x,y);return;}
}
int position(int x,int y,int qx,int qy,int r)
{
	if(qx<=x+r-1)return qy<=y+r-1?1:2;
	return qy<=y+r-1?3:4;
	
}
int dx[5]={0,0,0,-1,-1};
int dy[5]={0,0,-1,0,-1};
int ex[5]={0,0,0,1,1};
int ey[5]={0,0,1,0,1};
void work(int x,int y,int qx,int qy,int r)
{
	p[qx][qy]=1;
	if(r==2){Print(x,y);return;}
	r>>=1;
	int P=position(x,y,qx,qy,r);
	printf("%d %d %d\n",x+r+dx[P],y+r+dy[P],P);
	for(int i=1;i<=4;i++)
	{
		int nx=x+r*ex[i],ny=y+r*ey[i];
		int Nx=x+r+dx[5-i],Ny=y+r+dy[5-i];
		if(i==P)
			work(nx,ny,qx,qy,r);
		else 
			work(nx,ny,Nx,Ny,r);
	}
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	int k,qx,qy;
	scanf("%d\n%d %d",&k,&qx,&qy);
	work(1,1,qx,qy,(1<<k));
	return 0;
} 
