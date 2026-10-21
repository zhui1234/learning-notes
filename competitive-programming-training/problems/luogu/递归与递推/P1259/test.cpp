#include<iostream>
#include<cstdio>
using namespace std;

void Print(int n,string s)
{
	for(int i=1;i<=n;i++)
		cout<<s;
}
int n;
int n1,n2;


int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n-3;i++)
	{
		Print(n-i+1,"o"),Print(n-i+1,"*"),Print(2,"-"),Print(i-1,"o*");putchar('\n');
		Print(n-i,"o"),Print(2,"-"),Print(n-i,"*"),Print(i,"o*");putchar('\n');
	}
	Print(1,"ooo*o**--*"),Print(n-4,"o*");putchar('\n');
	Print(1,"o--*o**oo*"),Print(n-4,"o*");putchar('\n');
	Print(1,"o*o*o*--o*"),Print(n-4,"o*");putchar('\n');
	Print(1,"--"),Print(n,"o*");
	return 0;
} 
