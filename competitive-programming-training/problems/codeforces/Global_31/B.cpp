#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
void solve()
{
    cin >> n;
    string s = "", s1, s2, x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        s1 = x + s;
        s2 = s + x;
        if (s1 <= s2)
            s = s1;
        else
            s = s2;
    }
    cout << s << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
