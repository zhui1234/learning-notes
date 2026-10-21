#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, x, k;
void solve()
{
    cin >> x >> k;
    if (x % k == 0)
        printf("2\n%d 1\n", x - 1);
    else
        printf("1\n%d\n", x);
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
