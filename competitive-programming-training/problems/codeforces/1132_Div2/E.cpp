#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int a,b;
int prime[100010],tot;
bool p[200010];
void init()
{
    for(int i=2;i<=2e5;i++)
    {
        if(!p[i])
            prime[++tot]=i;
        for(int j=1;j<=tot && i*prime[j]<=2e5;j++)
        {
            p[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

int gcd(int x,int y)
{
    if(!x)return y;
    return gcd(y%x,x);
}
void solve()
{
    cin>>a>>b;
    if(gcd(a,b)==1)
    {
        cout<<"1\n"<<b-a<<'\n';
        return;
    }
    if(a==b)
    {
        cout<<"0\n";
        return;
    }
    int p=upper_bound(prime+1,prime+tot+1,a)-prime;
    if(prime[p]<b)
    {
        while(b%prime[p]==0)p++;
        cout<<"2\n"<<prime[p]-a<<' '<<b-prime[p]<<'\n';
    }
    else
    {
        int dp[110]={0},seq[110];
        for(int i=1;i<=b-a;i++)
        {
            dp[i]=0x7fffffff;
            for(int j=0;j<i;j++)
                if(gcd(a+i,a+j)==1)
                {
                    if(dp[i]>dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        seq[i]=j;
                    }
                }
            //cout<<a+i<<' '<<dp[i]<<' '<<a+seq[i]<<'\n';
        }
        cout<<dp[b-a]<<'\n';
        vector<int>ans;
        int now=b-a;
        do
        {
            ans.push_back(now-seq[now]);
            now=seq[now];
        } while (now);
        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin>>T;
    while (T--) solve();
    return 0;
}
