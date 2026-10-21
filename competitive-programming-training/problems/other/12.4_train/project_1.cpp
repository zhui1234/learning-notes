#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
void solve()
{
    string s;
    cin >> s;
    int len = s.size(), num = 1;
    if (s[0] == '0')
    {
        printf("0\n");
        return;
    }
    if (s[0] == '?') num *= 9;
    for (int i = 1; i < len; i++)
        if (s[i] == '?') num *= 10;
    printf("%d\n", num);
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
