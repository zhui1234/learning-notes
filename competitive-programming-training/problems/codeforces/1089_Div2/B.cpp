#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 200010;
int t;
int n;
int p[N];
bool pd(int x)
{
    int num = 0, mint = n + 1;
    for (int i = 1; i < mint; i++)
    {
        if (p[i] <= i)
            num++;
        else
        {
            if (min(mint, p[i]) - i + 1 + num >= x)
            {
                mint = min(mint, p[i]);
                num++;
            }
        }
    }
    return num >= x;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (pd(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
