#include<bits/stdc++.h>
using namespace std;

#define i64 long long
#define N 200010
int n,m;
vector<int>a,b;
map<vector<int>,int>p;
vector<vector<int> >q;
void init()
{
	int tot=0;
	for(int i=1;i<=n;i++)b.push_back(i);
	do
	{
		p[b]=tot++;
		q.push_back(b);
	}while(next_permutation(b.begin(),b.end()));
}
void solve()
{
	string order;
	cin>>order;
	if(order=="encode")
	{
		cin>>n;
		init();
		for(int i=1,x;i<=n;i++)cin>>x,a.push_back(x);
		cout<<p[a]<<endl;
	}
	else
	{
		cin>>n>>m;
		init();
		for(int i=0;i<q[m].size();i++)
			cout<<q[m][i]<<' ';
	}
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
