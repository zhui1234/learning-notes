#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
int n, k, x;

void solve()
{
    cin >> n >> k;
    int num = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &x);
        if (x)
        {
            if (last) num += min(k + 1, i - last);
            last = i;
        }
    }
    if (last) num += min(n - last + 1, k + 1);
    printf("%d\n", n - num);
}

int main()
{
   // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
