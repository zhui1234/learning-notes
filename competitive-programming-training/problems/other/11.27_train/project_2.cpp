#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
using ll = long long;

int t;
ll a, b, ans;
void solve()
{
    cin >> a >> b;
    ans = a + b;
    for (int i = 2; i <= 1e5; i++)
        ans = min(ans, (a + i - 1) / i + (b + i - 1) / i + i - 1);
    cout << ans << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
