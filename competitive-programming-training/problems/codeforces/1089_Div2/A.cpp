#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cout << n - i + 1 << ' ';
    cout << '\n';
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
