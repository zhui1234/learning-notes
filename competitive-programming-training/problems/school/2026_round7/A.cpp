#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int n;
int a[N];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	int ans=0;
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1])
		{
			if(i<n && a[i]==a[i+1]-1)
				a[i]--;
			else
				a[i]++;
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
