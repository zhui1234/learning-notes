#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int Mod=998857459;
int n,m;
i64 a[100010],f[100010]={0,1};
void solve()
{
    cin>>n>>m;
    for(int i=2;i<=n;i++)f[i]=(f[i-1]*i)%Mod;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=(a[i-1]+f[a[i]])%Mod;
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
