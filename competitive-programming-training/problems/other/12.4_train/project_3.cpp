#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010;
int t;
int Log[N] = {0, 1}, p[26], maxx[26];
void solve()
{
    string s;
    cin >> s;
    int len = s.size(), ans = 0x7fffffff;
    for (int i = 0; i < 26; i++) p[i] = maxx[i] = 0;
    for (int i = 1; i <= len; i++)
    {
        int digit = s[i - 1] - 'a';
        maxx[digit] = max(maxx[digit], i - p[digit] - 1);
        p[digit] = i;
    }
    for (int i = 0; i < 26; i++)
        if (p[i])
        {
            maxx[i] = max(maxx[i], len - p[i]);
            ans = min(ans, maxx[i]);
            // printf("%c %d\n", i + 'a', maxx[i]);
        }
    printf("%d\n", Log[ans]);
}

int main()
{
    // freopen("test.in", "r", stdin);
    for (int i = 1; i < N; i++) Log[i] = Log[i >> 1] + 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
