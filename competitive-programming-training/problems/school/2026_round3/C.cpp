#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
struct fire
{
    int row,col;
}a[1000010];

bool cmp(fire x1,fire x2)
{
    return x1.col<x2.col;
}

void solve()
{
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x)
                a[++m].row=i,a[m].col=j;
        }
    if(!m)
    {
        cout<<"YES\n";
        return;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
        if((i<m && (a[i].col==a[i+1].col || a[i+1].col-a[i].col < abs(a[i+1].row-a[i].row))) || a[i].col < a[i].row)
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;
    while (T--) solve();
    return 0;
}
