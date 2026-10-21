#include<bits/stdc++.h>
using namespace std;

const int N=110;
int n,t;
struct treasure
{
	int m,v;
	double V;
}a[N]; 
bool cmp(treasure x1,treasure x2)
{
	return x1.V>x2.V;
}
double ans;

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout); 
	scanf("%d %d\n",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i].m,&a[i].v),a[i].V=a[i].v*1.0/a[i].m;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n && t;i++)
		if(t-a[i].m>=0)
		{
			ans+=a[i].v;
			t-=a[i].m;
		}
		else
		{
			ans+=t*a[i].V;
			t=0;
		}
	printf("%.2lf",ans);
	return 0;
} 
