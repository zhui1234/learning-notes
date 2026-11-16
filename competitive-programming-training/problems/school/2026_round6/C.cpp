#include<bits/stdc++.h>
using namespace std;

#define i64 long long
int n,p,z,q;
int a[1000010];
int P[1000010],Z[1000010];

int main()
{
	scanf("%d %d %d %d\n",&n,&p,&z,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	P[n]=(a[n]==p)?n:-1;
	Z[n]=(a[n]==z)?n:-1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]==p)
			P[i]=i;
		else
			P[i]=P[i+1];
		if(a[i]==z)
			Z[i]=i;
		else
			Z[i]=Z[i+1];
	}
	int l,r,P_p,P_z;
	while(q--)
	{
		scanf("%d %d",&l,&r);
		P_p=(P[l]<=r)?P[l]:-1;
		P_z=(Z[l]<=r)?Z[l]:-1;
		//cout<<P_p<<' '<<P_z<<'\n';
		if(P_p==-1 && P_z==-1)
		{
			printf("n\n");
			continue;
		}
		if(P_p==-1 || ((P_z!=-1) && P_z<P_p))
		{
			printf("z\n");
			continue;
		}
		printf("p\n");
	}
	return 0;
}
