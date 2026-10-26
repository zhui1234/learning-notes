#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod=998244353;
i64 l,r;
int Log(i64 x)
{
    int res=0;
    for(int i=5;i>=0;i--)
        if(x>=(1LL<<(1<<i)))
        {
            x>>=(1<<i);
            res+=(1<<i);
        }
    return res;
}
int f(i64 x)
{
    if(x<=1)return x;
    if(x==2)return 3;
    if(x==3)return 2;
    int logx=Log(x);
    return min((i64)f(x-(1LL<<logx)+2)+logx+1,((1LL<<(logx+1))-x)%mod+logx)%mod;
}
void solve()
{
    cin>>l>>r;
    int sum=0;
    for(i64 i=l;i<=r;i++)
        sum=(sum+f(i))%mod;
    cout<<sum<<endl;
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
    cin>>T;
    while (T--) solve();
    return 0;
}
