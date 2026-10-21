#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
int n, k;
void solve()
{
    cin >> n >> k;
    if ((k & 1) == 1)
    {
        for (int i = 1; i <= k; i++) printf("%d ", n);
        printf("\n");
    }
    else
    {
        int x1 = 0, x2 = 0, i = 30;
        for (; i >= 0; i--)
            if (n & (1 << i))
            {
                x2 += (1 << i);
                i--;
                break;
            }
        while (i >= 0 && !(n & (1 << i))) i--;
        for (; i >= 0; i--)
            if (n & (1 << i))
            {
                x1 += (1 << i);
                i--;
                break;
            }
        for (; i >= 0; i--)
        {
            if (!(n & (1 << i))) x1 += (1 << i);
            x2 += (1 << i);
        }
        printf("%d %d", x1, x2);
        for (int i = 3; i <= k; i++) printf(" %d", n);
        printf("\n");
    }
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
