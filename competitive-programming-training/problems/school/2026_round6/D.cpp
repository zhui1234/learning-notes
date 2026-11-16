#include<bits/stdc++.h>
using namespace std;

#define i64 long long
int a,b,c;

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>a>>b>>c;
	int num1=(a!=0)+(b!=0)+(c!=0);
	int num2=(a>1)+(b>1)+(c>1);
	int num3=(a^b^c);
	if(num2==0)
	{
		if(num1%2==0)
			puts("Yes");
		else
			puts("No");
	}
	else
	{
		if(num3)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
