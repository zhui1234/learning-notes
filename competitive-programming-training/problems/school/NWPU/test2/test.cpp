#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

bool isdigit(char c){return c>='0' && c<='9';}
int t;
int a[3][60],b[3][60];
int l[3],ml;
string s;
int len;
void ss(int now)
{
	if(now>ml)
	{
		for(int i=0;i<=3;i++)
			for(int j=1;j<=l[i];j++)
				b[i][j]=a[i][j];
		return;
	}
	if(b[0][now]>a[0][now])return;
	if(b[0][now]==a[0][now] && b[1][now]>a[0][now])return;
	if(a[0][now]!=-1 && b[0][now]!=-1 && c[0][now]!=-1)return;
}

int main()
{
	freopen("test.in","r",stdin);
	scanf("%d\n",&t);
	while(t--)
	{
		getline(cin,s),len=s.size();
		ml=0;
		memset(b,0,sizeof(b));
		for(int i=0,j=1;i<len;i++)
		{
			if(s[i]=='+' || s[i]=='='){ml=l[j]>=ml?l[j]:ml;j=(j==1)?2:0;continue;}
			a[j][++l[j]]=isdigit(s[i])?s[i]^48:-1;
		}
		ss(1);
	}
	return 0;
}
