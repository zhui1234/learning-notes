#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;


int t;
int a[3][60],b[3][60];
int l[3],ml;
string s;
int len;
bool p;
bool isdigit(char c){return c>='0' && c<='9';}
int site(int i,int now)
{
	int x=l[i]-now+1;
	if(x>=1)
		return x;
	return 0;
}
void ss(int now,int carry)
{
	if(b[2][site(2,now-1)]>a[2][site(2,now-1)])
		return;
	if(b[2][site(2,now-1)]==a[2][site(2,now-1)] && b[0][site(0,now-1)]>a[0][site(0,now-1)])
		return;
	if(now>ml)
	{
		
		for(int i=0;i<3;i++)
			for(int j=1;j<=l[i];j++)
				b[i][j]=a[i][j];
		p=1;
		return;
	}
	if(a[0][site(0,now)]!=-1 && a[1][site(1,now)]!=-1 && a[2][site(2,now)]!=-1)
	{
		int x=a[0][site(0,now)]+a[1][site(1,now)]+carry;
		if(a[2][site(2,now)]!=x && a[2][site(2,now)]!=x-10)
			return;
		ss(now+1,x>9?1:0);
	}
	if(a[0][site(0,now)]==-1 && a[1][site(1,now)]==-1 && a[2][site(2,now)]==-1)
	{
		for(int i=9;i>=0;i--)
			for(int j=9;j>=0;j--)
			{
				a[2][site(2,now)]=i,a[0][site(0,now)]=j;
				int x=a[2][site(2,now)]-a[0][site(0,now)]-carry;
				a[1][site(1,now)]=x<0?(x+10):x;
				ss(now+1,x<0?1:0);
				a[2][site(2,now)]=a[0][site(0,now)]=-1;
				a[1][site(1,now)]=-1;
			}
	}	
	if(a[0][site(0,now)]!=-1 && a[1][site(1,now)]!=-1 && a[2][site(2,now)]==-1)
	{
		int x=a[0][site(0,now)]+a[1][site(1,now)]+carry;
		a[2][site(2,now)]=x>9?(x-10):x;
		ss(now+1,x>9?1:0);
		a[2][site(2,now)]=-1;
		return;
	}
	if(a[0][site(0,now)]==-1 && a[1][site(1,now)]!=-1 && a[2][site(2,now)]!=-1)
	{
		int x=a[2][site(2,now)]-a[1][site(1,now)]-carry;
		a[0][site(0,now)]=x<0?(x+10):x;
		ss(now+1,x<0?1:0);
		a[0][site(0,now)]=-1;
		return;
	}
	if(a[0][site(0,now)]!=-1 && a[1][site(1,now)]==-1 && a[2][site(2,now)]!=-1)
	{
		int x=a[2][site(2,now)]-a[0][site(0,now)]-carry;
		a[1][site(1,now)]=x<0?(x+10):x;
		ss(now+1,x<0?1:0);
		a[1][site(1,now)]=-1;
		return;
	}
	if(a[0][site(0,now)]!=-1 && a[1][site(1,now)]==-1 && a[2][site(2,now)]==-1)
	{
		for(int i=9;i>=0;i--)
		{
			a[2][site(2,now)]=i;
			int x=a[2][site(2,now)]-a[0][site(0,now)]-carry;
			a[1][site(1,now)]=x<0?(x+10):x;
			ss(now+1,x<0?1:0);
			a[2][site(2,now)]=-1;
			a[1][site(1,now)]=-1;
		}
	}
	if(a[0][site(0,now)]==-1 && a[1][site(1,now)]!=-1 && a[2][site(2,now)]==-1)
	{
		for(int i=9;i>=0;i--)
		{
			a[2][site(2,now)]=i;
			int x=a[2][site(2,now)]-a[1][site(1,now)]-carry;
			a[0][site(0,now)]=x<0?(x+10):x;
			ss(now+1,x<0?1:0);
			a[2][site(2,now)]=-1;
			a[0][site(0,now)]=-1;
		}
	}
	if(a[0][site(0,now)]==-1 && a[1][site(1,now)]==-1 && a[2][site(2,now)]!=-1)
	{
		for(int i=9;i>=0;i--)
		{
			a[0][site(0,now)]=i;
			int x=a[2][site(2,now)]-a[0][site(0,now)]-carry;
			a[1][site(1,now)]=x<0?(x+10):x;
			ss(now+1,x<0?1:0);
			a[1][site(1,now)]=-1;
			a[0][site(0,now)]=-1;
		}
	}
}

int main()
{
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d\n",&t);
	while(t--)
	{
		getline(cin,s),len=s.size();
		ml=p=0;
		memset(b,-1,sizeof(b));
		memset(l,0,sizeof(l));
		for(int i=0,j=0;i<len;i++)
		{
			if(s[i]=='+' || s[i]=='='){j++;continue;}
			a[j][++l[j]]=isdigit(s[i])?s[i]^48:-1;
		}
		ml=l[2];
		ss(1,0);
		if(!p){puts("Impossible");continue;}
		for(int i=1;i<=l[0];i++)printf("%d",b[0][i]);
		putchar('+');
		for(int i=1;i<=l[1];i++)printf("%d",b[1][i]);
		putchar('=');
		for(int i=1;i<=l[2];i++)printf("%d",b[2][i]);
		putchar('\n');
	}
	return 0;
}
