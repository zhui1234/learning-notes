#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
int s, k, m;
void solve()
{
    cin >> s >> k >> m;
    if (m / k % 2 == 0 || s <= k)
    {
        cout << max(0, s - (m % k)) << endl;
    }
    else
    {
        cout << max(0, max(0, k - (m % k))) << endl;
    }
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
