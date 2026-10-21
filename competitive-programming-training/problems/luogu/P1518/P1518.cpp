#include<iostream>
#include<cstdio>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct position
{
	int x,y;
};
position F,C;
int fw=0,cw=0;
bool p[20][20],q[1000000];
char c;
bool pd(position X)
{
	if(X.x<0 || X.x>=10 || X.y<0 || X.y>=10)return 0;
	if(p[X.x][X.y])return 0;
	return 1;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			scanf("%c",&c);
			if(c=='F'){F.x=i,F.y=j;continue;}
			if(c=='C'){C.x=i,C.y=j;continue;}
			p[i][j]=(c=='*');
		}
		scanf("\n");
	}
	position X;
	for(int t=0;;t++)
	{
		if(F.x==C.x && F.y==C.y){printf("%d",t);return 0;}
		X.x=F.x+dx[fw];
		X.y=F.y+dy[fw];
		if(pd(X)) F=X;
		else fw=(fw+1)%4;
		X.x=C.x+dx[cw];
		X.y=C.y+dy[cw];
		if(pd(X)) C=X;
		else cw=(cw+1)%4;
		int t=F.x+F.y*10+C.x*100+C.y*1000+fw*10000+cw*100000;
		if(q[t])break;
		q[t]=1;
	}
	printf("0");
	return 0;
} 
