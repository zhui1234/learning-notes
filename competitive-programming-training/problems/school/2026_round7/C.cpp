#include<bits/stdc++.h>
using namespace std;

#define i64 long long
const int N=200010;

int n;
int k,a[N];
void solve()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=(a[i]+a[i-1])%k;
	}
	if(a[n]==0)
	{
		printf("0\n");
		return;
	}
	map<int,int>p;
	p[a[n]]=0;
	int ans=n+1;
	for(int i=1;i<=n;i++)
	{
		if(p.find(a[i]) != p.end())
		{
			if(i-p[a[i]]<n)
                ans=min(ans,i-p[a[i]]);
			//printf("%d %d %d\n",a[i],p[a[i]],i);
		}
		p[(a[n]+a[i])%k]=i;
	}
	printf("%d\n",(ans!=n+1 ? ans:-1));
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
