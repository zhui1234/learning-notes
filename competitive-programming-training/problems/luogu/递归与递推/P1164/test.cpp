#include<iostream>
#include<cstdio>
using namespace std;

int n,m,a[110];
int f[10];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=a[i];j--)
			f[j]+=f[j-a[i]];
	printf("%d",f[m]);
	return 0;
} 
