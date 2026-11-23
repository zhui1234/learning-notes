#include<bits/stdc++.h>
using namespace std;

#define i64 long long
const int N=100010;
const int INF=0x7fffffff;

int n;
string s;
void solve()
{
	scanf("%d\n",&n);
	getline(cin,s);
	int t=0,cnt1=0,cnt2=0,ans1=0,ans2=0,last1=0,last2=0;
	int now,now1,now2;
    for(int i=0;i<n;i++)
	{
        now=s[i]-'0';
        now1=now^last1,now2=now^last2;
        if(now!=t)cnt1++;
		else cnt2++;
        if(now1!=t)
        {
            ans1++;
            last1=1;
        }
        else
            last1=0;
        if(now2!=(t^1))
        {
            ans2++;
            last2=1;
        }
        else
            last2=0;
        t^=1;

	}
    if((cnt1 & 1) && (cnt2 & 1)){printf("-1\n");return;}
    if(cnt1&1)ans1=INF;
    if(cnt2&1)ans2=INF;
	printf("%d\n",min(ans1,ans2));
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
