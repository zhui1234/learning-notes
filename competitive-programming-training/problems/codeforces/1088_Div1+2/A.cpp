#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
int n;
int a[110];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
    {
        puts("1");
        return;
    }
    for (int i = 1; i <= n; i++) cout << 2 << ' ';
    cout << '\n';
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
