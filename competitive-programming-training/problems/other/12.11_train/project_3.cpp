#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t;
string s;
int len;
void solve()
{
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '?')
        {
            if (!i)
                s[i] = '0';
            else
                s[i] = s[i - 1];
        }
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
