#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod=998244353;

int f[1000010]={1,1},g[1000010];

i64 Pow(int x,int y)
{
    i64 res=1;
    while(y)
    {
        if(y&1)res=1LL*res*x%mod;
        y>>=1;
        x=1LL*x*x%mod;
    }
    return res;
}

void init()
{
    // (num0-1)! / (c0-1)!*(num0-c0)!
    for(int i=2;i<=1e6;i++)f[i]=(1LL*f[i-1]*i)%mod;
    g[1000000]=Pow(f[1000000],mod-2);
    for(int i=1e6;i>=0;i--)g[i-1]=1LL*g[i]*i%mod;
}

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int c0=0,c1=0,num0=0,num1=0;
    for(int i=0;i<n;i++)
        if(s[i]=='0')
        {
            num0++;
            if(i==0 || s[i-1]=='1')c0++;
        }
        else
        {
            num1++;
            if(i==0 || s[i-1]=='0')c1++;
        }
    //cout<<c0<<' '<<c1<<'\n';
    int res0=num0?(1LL*f[num0-1]*g[c0-1])%mod*1LL*g[num0-c0]%mod:1;
    int res1=num1?(1LL*f[num1-1]*g[c1-1])%mod*1LL*g[num1-c1]%mod:1;
    cout<<1LL * res0 * res1 % mod<<'\n';
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin>>T;
    while (T--) solve();
    return 0;
}
