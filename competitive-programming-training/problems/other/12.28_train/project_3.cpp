#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100001, M = 10000010, Mod = 998244353;
int n, ans;
int s, a[N], b[N];
int head[N], to[M], Next[M], w[M], tot;
vector<int> z, q;
void add(int u, int v, int W)
{
    to[++tot] = v;
    w[tot] = W;
    Next[tot] = head[u];
    head[u] = tot;
}
void dfs(int u)
{
    for (int i = head[u]; i; i = Next[i])
    {
        z.push_back(w[i]);
        dfs(to[i]);
    }
}

void merge(int L, int R)
{
    if (L == R) return;
    int mid = (L + R) >> 1;
    merge(L, mid);
    merge(mid + 1, R);
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R)
    {
        if (z[i] <= z[j])
            q[k++] = z[i++];
        else
        {
            q[k++] = z[j++];
            ans = (ans + mid - i + 1) % Mod;
        }
    }
    while (i <= mid) q[k++] = z[i++];
    while (j <= R) q[k++] = z[j++];
    for (i = L; i <= R; i++) z[i] = q[i], q[i] = 0;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= s; j++) cin >> a[j] >> b[j];
        for (int j = s; j >= 1; j--) add(i, a[j], b[j]);
    }
    dfs(1);
    int len = z.size();
    q = vector<int>(len);
    merge(0, len - 1);
    cout << ans;
}

int main()
{
    // freopen("test.in", "r", stdin);
    solve();
    return 0;
}
