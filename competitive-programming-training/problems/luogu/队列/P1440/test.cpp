#include<bits/stdc++.h>
using namespace std;

const int N=1000010; 
int n,m;
int a[N];
struct node
{
	int num,id;
	operator < (node x1,node x2)
	{
		return x1.num>x2.num;
	}
};
priority_queue<node>q;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')sum=(sum*10)+(c^48),c=getchar();
	return sum;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	n=read(),m=read();
	return 0;
} 
