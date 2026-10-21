#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int n;
struct contest
{
	int a,b;
}t[N];
bool cmp(contest x1,contest x2)
{
	if(x1.b!=x2.b)return x1.b<x2.b;
	return x1.a>x2.a;
}
int now,num;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(t[i].a<now)continue;
		now=t[i].b;
		num++;
	} 
	printf("%d",num);
	return 0;
} 
