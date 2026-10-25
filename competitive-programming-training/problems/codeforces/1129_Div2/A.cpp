#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n,k;
int a[110];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=0,j=1;j<=n;i++)
    {
        if(a[j]!=i)
        {
            cout<<i<<endl;
            return;
        }
        while(a[j]==i && j<=n)j++;
        j--;
        if(j<(i+1)*k)
        {
            cout<<i<<endl;
            return;
        }
        j++;
    }
    cout<<a[n]+1<<endl;
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
