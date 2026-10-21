#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
void solve()
{
    int k, x;
    cin >> k >> x;
    cout << k * x + 1 << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
