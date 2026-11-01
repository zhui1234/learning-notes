#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
int a[200010];
void solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==n)cout<<"-1\n";
    else if(sum==a[1]+n-1)cout<<a[1]<<'\n';
    else if(sum==a[n]+n-1)cout<<a[n]<<'\n';
    else if(sum==a[1]+a[n]+n-2)cout<<a[1]+a[n]-1<<'\n';
    else cout<<sum-1<<'\n';
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
