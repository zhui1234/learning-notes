#include<iostream>
#include<cstdio>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;

char s[40];
long long len,x,n;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s %lld",s,&n);
	len=strlen(s);
	while(n>len)
	{
		x=len;
		while((x<<1)<n)x<<=1;
		n-=x+1;
		if(!n)n=x;
	}
	printf("%c",s[n-1]);
	return 0;
} 
