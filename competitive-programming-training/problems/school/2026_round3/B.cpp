#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
int a[100010];
void solve()
{
    cin>>n;
    int minn=0x7fffffff,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=minn)
        {
            minn=a[i];
            ans=i;
        }
    }
    cout<<ans;
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
