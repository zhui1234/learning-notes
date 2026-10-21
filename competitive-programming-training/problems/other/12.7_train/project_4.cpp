#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const int N = 1010;
int n, q, k;
int a[N];
priority_queue<int, vector<int>, greater<int>> red;
priority_queue<int, vector<int>, less<int>> blue;
bool check(ll x)
{
    for (int i = 1; i <= n; i++) red.push(a[i] - x);
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", !red.empty() ? red.top() : 0,
               !blue.empty() ? blue.top() : 0);
        if (!blue.empty())
        {
            if (blue.top() - i >= 0)
            {
                red.push(blue.top() - i);
                blue.pop();
                continue;
            }
        }
        if (!red.empty())
        {
            blue.push(red.top() + i);
            red.pop();
            continue;
        }
        red.push(blue.top() - i);
        blue.pop();
    }
    printf("%d %d\n\n", !red.empty() ? red.top() : 0,
           !blue.empty() ? blue.top() : 0);
    bool p = 1;
    while (!red.empty())
    {
        if (red.top() < 0) p = 0;
        red.pop();
    }
    while (!blue.empty())
    {
        if (blue.top() < 0) p = 0;
        blue.pop();
    }
    return p;
}
void solve()
{
    cin >> k;
    ll l = a[1], r = a[1] + k * (k + 1) / 2, ans = l;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid, ans = mid;
        else
            r = mid - 1;
    }
    // printf("%lld ", ans);
}

int main()
{
    freopen("test.in", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    while (q--) solve();
    return 0;
}
