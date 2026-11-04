#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod=998244353;
int n,m;
int g[2][610][610];
void solve()
{
    cin>>n>>m;
    for(int j=m;j>=1;j--)
        for(int k=j;k>=1;k--)
            g[1][j][k]=1;
    for(int i=2,I=0;i<=n;i++,I^=1)
        for(int j=m;j>=1;j--)
        {
            g[I][j][j+1]=0;
            for(int k=j;k>=1;k--)
            {
                if(j+k*(n-i)<m)break;
                int x=g[I^1][j][k],y=0;
                if(j-k>=k)
                {
                    x+=g[I^1][j-k][k];
                    if(x>=mod)x-=mod;
                }
                y=g[I][j][k+1]+x;
                if(y>=mod)y-=mod;
                g[I][j][k]=y;
            }
        }
    cout<<g[n&1][m][1]<<endl;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;
    while (T--) solve();
    return 0;
}
