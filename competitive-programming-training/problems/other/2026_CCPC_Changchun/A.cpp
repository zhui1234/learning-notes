#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n,m;
    i64 sum=0,ans=0;
    cin>>n>>m;
    vector<vector<i64>>a(n,vector<i64>(m+1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int j=0;j<m;j++)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i][j];
            sum=max(sum-a[i][j+1],0LL);
        }
        ans+=sum;
    }
    cout<<ans;
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
    while (T--) solve();
    return 0;
}
