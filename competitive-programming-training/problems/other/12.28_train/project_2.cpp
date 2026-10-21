#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100010, M = 2000010;
int n;
int p[N], q[N], a[M], b[M], ans;
int f[N] = {1};
void solve()
{
    for (int i = 1; i < N; i++) f[i] = (f[i - 1] << 1) % 998244353;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[p[i]];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> b[p[i]];
    for (int i = 2; i < M; i++)
        if (a[i] != b[i])
        {
            if (a[i] < b[i])
            {
                cout << 0;
                return;
            }
            ans++;
        }
    cout << f[ans];
}

int main()
{
    // freopen("test.in", "r", stdin);
    solve();
    return 0;
}
