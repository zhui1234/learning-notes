#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int Mod = 676767677;
int t;
int x, y;
bool p[200010];
int prime[200010], tot;
long long cal(int X)
{
    if (X <= 1) return 1;
    long long num, sum = 1;
    for (int i = 1; i <= tot && prime[i] <= X; i++)
    {
        num = 0;
        while (X % prime[i] == 0) X /= prime[i], num++;
        sum *= num + 1;
    }
    return sum;
}
void solve()
{
    cin >> x >> y;
    int X = abs(x - y);
    cout << cal(X) % Mod << '\n';
    for (int i = 1; i <= x; i++) cout << 1 << ' ';
    for (int i = 1; i <= y; i++) cout << -1 << ' ';
    cout << '\n';
}

int main()
{
    freopen("test.in", "r", stdin);
    for (int i = 2; i <= 200000; i++)
    {
        if (!p[i]) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] <= 200000; j++)
        {
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    cin >> t;
    while (t--) solve();
    return 0;
}
