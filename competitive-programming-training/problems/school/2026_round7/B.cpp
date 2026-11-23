#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int n,k;
int a[N];
void solve()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	int ans=0;
	while(l<=r)
	{
		if(l<r && a[r]+a[l]<=k) l++,r--;
		else r--;
		ans++;
	}
	printf("%d\n",ans);
}

int main()
{
	//freopen("out.txt","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
