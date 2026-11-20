#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=1000010;
int n,q;
int a[N],b[N][N],c[N][N],ans[N][N];

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            ans[i][j]=b[i][j]=b[j][i]=gcd(a[i],a[j]);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
            for(int j=1;j<=n;j++)
            {
                c[i][j]=min(c[i][j],min(b[i][k],c[k][j]));
                ans[i][j]=max(ans[i][j],c[i][j]);
            }
    }
    int x,y;
    while(q--)
    {
        cin>>x>>y;
        cout<<ans[x][y]<<'\n';
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
