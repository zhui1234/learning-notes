#include<iostream>
#include<cstdio>
using namespace std;

int n,now,id;
int a[1000010]; 
int num(int x)
{
	if(x<n)return x+1;
	return 1;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	now=id=1;
	for(int i=1;id<=n;i++,now=num(now))
	{
		while(a[now])
			now=num(now);
		if(i&1)continue;
		a[now]=id,id++;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
} 
