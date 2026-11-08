#include<bits/stdc++.h>
using namespace std;

#define i64 long long
#define N 200010
#define mod 998244353
int n;
int a[N];
int f[N][2];

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1][0]=f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			f[i][0]+=f[i-1][0];
			f[i][1]+=f[i-1][1];
			if(f[i][0]>mod)f[i][0]-=mod;
			if(f[i][1]>mod)f[i][1]-=mod;
		}
		if(i-1-a[i-1]==a[i])
		{
			f[i][1]+=f[i-1][0];
			f[i][0]+=f[i-1][1];
			if(f[i][0]>mod)f[i][0]-=mod;
			if(f[i][1]>mod)f[i][1]-=mod;
		}
	}
	cout<<(f[n][1]+f[n][0])%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
