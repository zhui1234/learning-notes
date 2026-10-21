#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int w,h;
char c[2000][2000];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	memset(c,' ',sizeof(c));
	c[0][1]='/',c[0][2]='\\';
	c[1][0]='/',c[1][1]=c[1][2]='_',c[1][3]='\\';
	w=4,h=2;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<h;j++)
			for(int k=0;k<w;k++)
				c[j][k+w]=c[j+h][k+(w>>1)]=c[j][k];
		h<<=1;
		w<<=1;
	}
	for(int i=(1<<n);i>0;i-=2)
	{
		for(int j=0;j<w;j++)
			putchar(c[i-2][j]);
		putchar('\n');
		for(int j=0;j<w;j++)
			putchar(c[i-1][j]);
		putchar('\n');
	}
	return 0;
} 
