#include<bits/stdc++.h>
#define Abs(x) x>0?x:-x
using namespace std;

inline long long read()
{
	long long sum=0;
	char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')sum=(sum<<1)+(sum<<3)+(c^48),c=getchar();
	return sum;
}
const int N=100010;
int n,m;
long long a[N];
long long query(long long k)
{
	int l=1,r=n;
	int id=1;
	while(l<=r)
	{
		int mid=((l+r)>>1);
		if(Abs(a[mid]-k)<Abs(a[id]-k))
	}
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	while(m--)
		printf("%lld\n",query(read()));
	return 0;
} 
