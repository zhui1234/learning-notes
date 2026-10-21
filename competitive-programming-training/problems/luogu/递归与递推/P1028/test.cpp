/*
#include<iostream>
#include<cstdio>
using namespace std;

int upint(int x)
{
	if(x&1)return ((x+1)>>1);
	return (x>>1);
}
int downint(int x)
{
	if(x&1)return ((x-1)>>1);
	return (x>>1);
}
int n;
long long f[1010],sum;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	f[n]=sum=1;
	for(int i=downint(n);i>=1;i--)
	{
		for(int j=(i<<1);j<=downint(n);j++)
			f[i]+=f[j];
		f[i]++;
		sum+=f[i];
	}
	printf("%lld",sum);
	return 0;
} 
*/
#include<iostream>
#include<cstdio>
using namespace std;

int downint(int x)
{
	if(x&1)x--;
	return x>>1;
}
int n;
long long f[1010],g[1010];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=g[downint(i)]+1,g[i]=g[i-1]+f[i];
	printf("%lld",f[n]);
}