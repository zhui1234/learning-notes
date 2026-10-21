#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 200010;
int t, n, k;
ll a[N];
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    ll maxx = 0;
    for (int i = 0; i <= k; i++) maxx = max(maxx, a[n - k + i] - a[2 * i]);
    cout << maxx << endl;
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
