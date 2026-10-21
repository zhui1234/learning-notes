#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int n;
struct p
{
	int t,id;
}a[N]; 
bool cmp(p x1,p x2)
{
	if(x1.t!=x2.t)return x1.t<x2.t;
	return x1.id<x2.id;
}
double T,ans;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].t),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i].id);
		ans+=T;
		T+=a[i].t;
	}
	printf("\n%.2lf",ans/n);
	return 0;
} 
