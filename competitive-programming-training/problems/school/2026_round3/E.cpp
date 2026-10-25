#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=1000010;
const int mod=998244353;
i64 n,q,k,x,pos;
int f=1,g[N];
i64 Pow(i64 a,i64 b)
{
    i64 res=1;
    a%=mod;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void solve()
{
    cin>>n>>q;
    for(int i=2;i<=n;i++)f=(i64)(f*i)%mod;
    g[n]=Pow(f,mod-2);
    for(int i=n;i>=1;i--)g[i-1]=(i64)g[i]*i%mod;
    for(int i=1;i<=q;i++)
    {
        cin>>k>>x;
        bool p=0;
        for(int j=0;j<=60 && k+j<n;j++)
            if(x<=((long long)1<<j))
            {
                p=1;
                cout<<((i64)f * (i64)g[k+j])%mod<<'\n';
                break;
            }
        if(!p)
            cout<<1<<'\n';
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

    int T = 1;
    while (T--) solve();
    return 0;
}
