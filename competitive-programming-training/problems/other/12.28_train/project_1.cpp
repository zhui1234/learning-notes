#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, x, minn = 0x7fffffff;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        minn = min(minn, abs(x));
    }
    cout << minn;
}
int main()
{
    // freopen("test.in","r",stdin);
    solve();
    return 0;
}
