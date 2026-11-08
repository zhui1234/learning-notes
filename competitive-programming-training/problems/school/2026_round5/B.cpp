#include<bits/stdc++.h>
using namespace std;

#define i64 long long
#define N 10010
int n,m;
i64 s[N],h[N],z[N];
map<string,int>station;
string low(string x)
{
	int len=x.size();
	string res="";
	for(int i=0;i<len;i++)
		if(x[i]>='A' && x[i]<='Z')
			res+=x[i]-'A'+'a';
		else
			res+=x[i];
	return res;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string sta;
		cin>>sta>>s[i]>>h[i]>>z[i];
		station[low(sta)]=i;
	}
	string name,sta,medal,type;
	i64 num,a,b,c;
	i64 sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>name>>sta>>medal>>type;
		cin>>num>>a>>b>>c;
		int id=station[low(sta)];
		if(type!="REGULAR" || medal=="IRON" || a!=s[id]){
			cout<<"REFUSE\n";
			continue;
		}
		if(b > 2 * h[id] * num || c > 2 * z[id] * num){
			cout<<"REFUSE\n";
			continue;
		}
		sum+=a+b+c+80*num;
		cout<<"ACCEPT\n";
	}
	cout<<sum;
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
