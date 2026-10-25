#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int INF=0x3f3f3f3f;
int n;
int a[200010];

void solve()
{
    cin>>n;
    int minn=INF;
    for(int i=1;i<=n;i++)cin>>a[i],minn=min(minn,a[i]);
    if(minn<n)
        cout<<n<<endl;
    else
        cout<<0<<endl;
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
