#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010;
int t, n, a[N], b[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int l = 1, r = n;
    while (a[l] == b[l] && l <= n) l++;
    while (a[r] == b[r] && r >= 1) r--;
    while (l > 1 && a[l - 1] <= b[l]) l--;
    while (r < n && a[r + 1] >= b[r]) r++;
    printf("%d %d\n", l, r);
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
