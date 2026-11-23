#include<bits/stdc++.h>
using namespace std;

#define i64 long long
const int N=100010;

int n,k;
struct Data
{
	int a,d;
}t[N];
bool cmp(Data x1,Data x2)
{
	if(x1.d!=x2.d)	return x1.d<x2.d;
	return x1.a<x2.a;
}
bool pd(i64 x)
{
	i64 sum=0;
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
        q.push(t[i].a);
        sum+=t[i].a;
        if(sum > 1LL*t[i].d*x)
        {
            sum-=q.top();
            q.pop();
        }
	}
	return (int)q.size()>=k;
}
void solve()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&t[i].a,&t[i].d);
	}
	sort(t+1,t+n+1,cmp);
	i64 l=1,r=100000000000,ans;
	while(l<=r)
	{
		i64 mid=(l+r)/2;
		if(pd(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
