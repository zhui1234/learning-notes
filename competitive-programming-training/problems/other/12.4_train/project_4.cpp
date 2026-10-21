#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010, Max = 0x7fffffff;
int t, n, m, k;
int f[N], ans;
struct node
{
    int l, r;
    int num;
} a[N];
void ss(int x, int y, int z, int last)
{
    if (x > n || y >= ans) return;
    if (f[n] - f[x - 1] < z) return;
    if (!z)
    {
        ans = y;
        return;
    }
    for (int i = x; i <= n; i++)
    {
        if (a[i].num >= z)
        {
            ans = min(ans, y + a[i].l - last + z + 1);
            continue;
        }
        ss(i + 1, y - last + a[i].r + 2, z - a[i].num, a[i].r);
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].l;
    for (int i = 1; i <= n; i++)
        cin >> a[i].r, a[i].num = a[i].r - a[i].l + 1,
                       f[i] = f[i - 1] + a[i].num;
    ans = Max;
    ss(1, 0, k, 0);
    if (ans == Max)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
