#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
int l, a, b;
int gcd(int x, int y)
{
    if (x < y) swap(x, y);
    if (!y) return x;
    return gcd(y, x % y);
}
void solve()
{
    cin >> l >> a >> b;
    b %= l;
    if (!b)
    {
        printf("%d\n", a);
        return;
    }
    if (gcd(l, b) == 1)
    {
        printf("%d\n", l - 1);
        return;
    }
    int maxx = 0;
    for (int i = 0;; i++)
    {
        maxx = max(maxx, (a + b * i) % l);
        if (i && (a + b * i) % l == a) break;
    }
    printf("%d\n", maxx);
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
