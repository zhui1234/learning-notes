#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
long long f[1010]={0,1};

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=2;i<=(m-n+1);i++)
		f[i]=f[i-1]+f[i-2];
	printf("%lld",f[m-n+1]);
	return 0;
} 
