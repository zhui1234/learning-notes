#include<iostream>
#include<cstdio>
using namespace std;

const int mod=10000;
int n;
int f[1000010],g[1000010];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	f[1]=1,f[2]=2,g[2]=2;
	for(int i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-2]+g[i-1])%mod;
		g[i]=(f[i-2]*2+g[i-1])%mod;
	}
	printf("%d",f[n]);
	return 0;
} 
