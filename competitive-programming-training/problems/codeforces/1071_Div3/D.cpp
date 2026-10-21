#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
void solve()
{
    cin >> n;
    for (int i = (1 << n); i > 0; i >>= 1)
        for (int j = i - 1; j < (1 << n); j += (i << 1)) cout << j << ' ';
    cout << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
