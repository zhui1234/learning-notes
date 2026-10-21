#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

string s;
int len,now;
string ss()
{
	string t("\0"),T("\0");
	int num=0;
	now++;
	while(s[now]>='0' && s[now]<='9')num=(num<<1)+(num<<3)+(s[now]^48),now++;
	while(s[now]!=']')
	{
		while(s[now]>='A' && s[now]<='Z')t+=s[now],now++;
		if(s[now]=='[')
			t+=ss(),now++;
	}
	while(num--)
		T+=t;
	return T;
}
string ans;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>s;
	len=s.size();
	while(now<len)
	{
		if(s[now]>='A' && s[now]<='Z')ans+=s[now];
		else ans+=ss();
		now++;
	}
	cout<<ans<<endl;
	return 0;
} 
