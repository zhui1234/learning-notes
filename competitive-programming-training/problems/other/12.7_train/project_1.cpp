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
    int len = s.size();
    int p[26], num = 0;
    for (int i = 0; i < 26; i++) p[i] = 0;
    for (int i = 0; i < len / 2; i++)
        if (!p[s[i] - 'a']) p[s[i] - 'a']++, num++;
    if (num > 1)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
