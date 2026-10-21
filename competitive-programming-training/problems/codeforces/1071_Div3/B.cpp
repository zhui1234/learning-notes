#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010;
int t;
int n;
int a[N], b[N], sum, maxx;
void solve()
{
    cin >> n;
    sum = maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        b[i] = abs(a[i] - a[i - 1]);
        sum += b[i];
    }
    sum -= a[1];
    maxx = max(b[2], b[n]);
    for (int i = 2; i < n; i++)
        maxx = max(maxx, b[i] + b[i + 1] - abs(a[i + 1] - a[i - 1]));
    cout << sum - maxx << endl;
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
