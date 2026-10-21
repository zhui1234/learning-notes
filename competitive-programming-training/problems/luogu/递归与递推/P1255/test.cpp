#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int n;
int a[5010][1010];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	a[1][0]=a[1][1]=a[2][0]=1;
	a[2][1]=2;
	for(int i=3;i<=n;i++)
	{
		a[i][0]=max(a[i-1][0],a[i-2][0]);
		for(int j=1;j<=a[i][0];j++)
		{
			a[i][j]+=a[i-1][j]+a[i-2][j];
			if(a[i][j]>9)a[i][j]-=10,a[i][j+1]++;
		}
		if(a[i][a[i][0]+1])a[i][0]++;
	}
	for(int i=a[n][0];i>=1;i--)
		printf("%d",a[n][i]);
	return 0;
} 
