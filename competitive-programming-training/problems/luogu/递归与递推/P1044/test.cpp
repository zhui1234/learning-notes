#include<iostream>
#include<cstdio>
using namespace std;

int n;
int f[20]={1,1};

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i]+=f[j-1]*f[i-j];
    printf("%d",f[n]);
	return 0;
}

