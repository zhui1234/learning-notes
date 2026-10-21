/*
#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

int n,m;
int k,p,x;
list<int>L;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d\n",&n);
	L.push_front(1);
	for(int i=2;i<=n;i++)
	{
		scanf("%d %d\n",&k,&p);
		list<int>::iterator it=L.begin();
		while(it!=L.end() && *it!=k)
			it++;
		if(it==L.end() && p)
			{L.push_back(i);continue;}
		if(p)
			it++;
		L.insert(it,i);
	}
	scanf("%d\n",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d\n",&x);
		L.remove(x);
	}
	for(list<int>:: iterator it=L.begin();it!=L.end();it++)
		printf("%d ",*it);
	return 0;
} 
*/
#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

const int N=100010;
int n,m;
int k,p,x;
int pre[N],Next[N];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d\n",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d %d\n",&k,&p);
		if(!p)
			Next[pre[k]]=i,pre[i]=pre[k],pre[k]=i,Next[i]=k;
		else
			pre[Next[k]]=i,Next[i]=Next[k],Next[k]=i,pre[i]=k;
	}
	scanf("%d\n",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d\n",&x);
		if(pre[x]==-1)
			continue;
		Next[pre[x]]=Next[x];
		pre[Next[x]]=pre[x];
		Next[x]=pre[x]=-1;
	}
	for(int i=1;i<=n;i++)
		if(!pre[i])
		{
			int now=i;
			while(now)
			{
				printf("%d ",now);
				now=Next[now];
			}
			break;
		}
	return 0;
} 