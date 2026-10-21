#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010;
int t, n;
int a[N];
void solve()
{
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
        {
            for (int j = 0; i + j < n; j++) a[j] = s[i + j] - '0';
            for (int j = n - i; j < n; j++) a[j] = 0;
            break;
        }
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
