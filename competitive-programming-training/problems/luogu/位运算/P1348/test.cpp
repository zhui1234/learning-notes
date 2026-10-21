#include<iostream>
#include<cstdio>
using namespace std;

int a,b;
int sum;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d %d",&a,&b);
	for(int i=a;i<=b;i++)
		if((i&1) || !(i&3))
			sum++;
	printf("%d",sum);
	return 0;
} 
