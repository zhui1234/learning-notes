#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
void solve()
{
    cin >> n;
    if (n <= 3)
    {
        cout << n << endl;
        return;
    }
    cout << n % 2 << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
