#include<iostream>
#include<cstdio>
using namespace std;

inline int read()
{
	int sum=0;
	char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
	return sum;
}
int n,x;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;i++)x^=read();
	printf("%d",x);
	return 0;
} 
