#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

//const int N=1010,M=5010;
const int N=10,M=10;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
inline int read()
{
	char c = getchar();
	int sum = 0;
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
	return sum;
}
int t,n,m;
bool map[N][N];
int a[M][2],p[M],ans[M];
int num,sum;
void ss(int Num)
{
	if(Num==1)
	{
		for(int i=1;i<=num;i++)
			if(p[i])
			{
				ans[i]=1;
				break;
			}
		return;
	}
	if(!Num)return;
	for(int i=0;i<=3;i++)
	{
		int x=0;
		int ts[M]={0};
		for(int j=1;j<=num;j++)
		{
			a[j][0]+=dx[i],a[j][1]+=dy[i];
			if(!p[j])continue;
			if(a[j][0]<0 || a[j][0]>=n || a[j][1]<0 || a[j][1]>=m)
				p[j]=0,x++,ts[++ts[0]]=j;
			else
				if(!map[a[j][0]][a[j][1]])
					p[j]=0,x++,ts[++ts[0]]=j;
		}
		ss(Num-x);
		for(int j=1;j<=num;j++)
			a[j][0]-=dx[i],a[j][1]-=dy[i];
		for(int j=1;j<=ts[0];j++)
			p[ts[j]]=1;
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read();
		num=sum=0;
		for(int i=1;i<=n*m;i++)p[i]=ans[i]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if(getchar()==46)
					a[++num][0]=i,a[num][1]=j,map[i][j]=1,p[num]=1;
				else
					map[i][j]=0;
			getchar();
		}
		ss(num);
		for(int i=1;i<=num;i++)
			sum+=ans[i];
		printf("%d\n",sum);
	}
	return 0;
}	