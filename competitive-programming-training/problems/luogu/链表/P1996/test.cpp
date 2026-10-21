#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
int next[110];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<n;i++)next[i]=i+1;next[n]=1;
	int now=1,pre;
	while(n>1)
	{
		n--;
		for(int i=1;i<m;i++)pre=now,now=next[now];
		printf("%d ",now);
		next[pre]=next[now];
		now=next[now];
	}
	printf("%d",now);
	return 0;
}
//动态链表

//STL list
 