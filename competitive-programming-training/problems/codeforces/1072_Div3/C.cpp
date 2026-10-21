#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int t, n, k;
void solve()
{
    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1;; i++)
    {
        int l = (k << i) - (1 << i) + 1, r = (k << i) + (1 << i) - 1;
        if (l > n) break;
        if (l <= n && n <= r)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
