#include<bits/stdc++.h>
using namespace std;

#define i64 long long
#define N 200010
int n;
int head[N],Next[N],to[N],tot;
int s[N];
int dfs(int x)
{
	int sum=0;
	for(int i=head[x];i;i=Next[i])
		sum+=dfs(to[i]);
	if(s[x] != sum && s[x] != sum+1)
	{
		cout<<0<<endl;
		exit(0);
	}
	return s[x];
}

void solve()
{

	cin>>n;
	for(int i=2,p;i<=n;i++)
	{
		cin>>p;
		to[++tot]=i;
		Next[tot]=head[p];
		head[p]=tot;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	dfs(1);
	cout<<1<<endl;
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
