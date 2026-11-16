#include<bits/stdc++.h>
using namespace std;

#define i64 long long
int q,opt,num;
int a[500010],top;
int id[500010];

int main()
{
	cin>>q;
	while(q--)
	{
		cin>>opt;
		if(opt==1)
		{
			cin>>num;
			a[++top]=num;
			id[num]=top;
		}
		else if(opt==2)
		{
			top--;
		}
		else
		{
			cin>>num;
			cout<<id[num]<<'\n';
		}
	}
	return 0;
}
