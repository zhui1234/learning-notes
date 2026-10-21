#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300010;
int t, n;
int x, lx, now, num, p;
void solve()
{
    cin >> n;
    lx = -1, p = 0, num = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (lx >= 0 && lx != x)
        {
            // cout << p << ' ' << now << ' ' << lx << ' ' << x << endl;
            if (!p)
                now = (x > lx);
            else if ((x > lx) ^ now)
                now = now ^ 1, num++;
            p = 1;
        }
        lx = x;
    }
    cout << num + p << endl;
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
