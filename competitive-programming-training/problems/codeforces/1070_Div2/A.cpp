#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int t;
priority_queue<int, vector<int>, greater<int>> q;
void solve()
{
    int n, a[110];
    cin >> n;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        while (!q.empty() && q.top() < a[i]) q.pop();
        q.push(a[i]);
    }
    cout << n - q.size() << endl;
}

int main()
{
    // freopen("test.in","r",stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
