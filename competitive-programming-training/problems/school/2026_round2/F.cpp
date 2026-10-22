#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,k;
int a[200010];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        if(k>=n-i)
        {
            a[i]=n-i+1;
            k-=n-i;
        }
        else
        {
            for(int j=1;j<=k;j++)
                a[n-j+1]=n-i-j+1;
            a[n-k]=n-i+1;
            for(int j=1;n-k-j>=i;j++)
                a[n-k-j]=n-i-k+1-j;
            break;
        }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--) solve();
    return 0;
}
