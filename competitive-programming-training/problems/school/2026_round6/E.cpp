#include<bits/stdc++.h>
using namespace std;

#define i64 long long
int n;
int h,st[1000010][2],top;

int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h);
		if(!top || h+i>st[1][0])
		{
			printf("-1 ");
			top=1;
			st[top][0]=h+i;
			st[top][1]=i;
		}
		else
		{
			int l=1,r=top,ans=0;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(st[mid][0]<=h+i)
					r=mid;
				else
					l=mid+1;
			}
			if(st[r][0]>=h+i) ans=st[r][1];
			if(st[r][0]>h+i) top=r+1;
			else top=r;
			st[top][0]=h+i,st[top][1]=i;
			for(int j=1;j<r;j++)
				if(st[j][1]>ans)
					ans=st[j][1];
			printf("%d ",ans);
		}/*
		printf("%d!!",top);
		for(int j=1;j<=top;j++)
			printf("%d,%d ",st[j][0],st[j][1]);
		printf("\n");*/
	}
	return 0;
}
