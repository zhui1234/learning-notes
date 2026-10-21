#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    int num = 1, maxx = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            num++;
        else
            num = 1;
        maxx = max(maxx, num);
    }
    printf("%d\n", maxx + 1);
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
