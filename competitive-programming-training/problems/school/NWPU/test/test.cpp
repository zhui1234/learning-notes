#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

typedef long long ll; 
int t;
ll n,k,K;

int main()
{
	//freopen("test.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		ll l=1,r=1e9,num;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(k*mid>=n)
				r=mid-1,num=mid;
			else
				l=mid+1;
		}
		k*=num;
		printf("%lld\n",(k+n-1)/n);
	}
	return 0;
}
