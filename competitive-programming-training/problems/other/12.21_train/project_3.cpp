#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 200010;
const int value[6] = {0, 1, 10, 100, 1000, 10000};
int t;
int a[N], pos[6][2];
string s;
int len;
ll cal()
{
    ll result = 0;
    int maxx = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (a[i] < maxx)
            result -= value[a[i]];
        else
        {
            result += value[a[i]];
            maxx = a[i];
        }
    }
    return result;
}
void solve()
{
    cin >> s;
    len = s.size();
    for (int i = 1; i <= 5; i++) pos[i][0] = pos[i][1] = -1;
    for (int i = 0; i < len; i++)
    {
        a[i] = s[i] - 'A' + 1;
        if (pos[a[i]][0] < 0)
            pos[a[i]][0] = i;
        else
            pos[a[i]][1] = i;
    }
    ll ans = -1e9;
    for (int i = 1; i <= 5; i++)
        if (pos[i][0] >= 0)
        {
            for (int j = 1; j <= 5; j++)
            {
                a[pos[i][0]] = j;
                ans = max(ans, cal());
                a[pos[i][0]] = i;
                if (pos[i][1] < 0) continue;
                a[pos[i][1]] = j;
                ans = max(ans, cal());
                a[pos[i][1]] = i;
            }
        }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
