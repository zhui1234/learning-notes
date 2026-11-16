#include<bits/stdc++.h>
using namespace std;

#define i64 long long
int n;
int a[1000010],b[1000010];
i64 ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)ans+=a[i]*b[i];
	cout<<ans;
	return 0;
}
