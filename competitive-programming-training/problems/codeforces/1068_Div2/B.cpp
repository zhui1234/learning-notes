#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
int n;
long long a[100010], b[100010];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    long long maxx = 0, minn = 0, x;
    for (int i = 1; i <= n; i++)
    {
        x = max(maxx - a[i], b[i] - minn);
        minn = min(minn - a[i], b[i] - maxx);
        maxx = x;
    }
    printf("%lld\n", maxx);
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
