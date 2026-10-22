#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 a,b,t;

void solve()
{
    cin>>a>>b;
    t=a/b;
    cout<<(t+1)*a - t*(t+1)/2*b<<endl;
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
