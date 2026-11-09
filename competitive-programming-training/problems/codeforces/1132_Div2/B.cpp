#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
int a[110];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    i64 x=0,y=0,ans=1;
    int l=1,r=n;
    while(l<=r)
    {
        x+=(1<<a[r--]);
        if(l<=r)y+=(1<<a[r--]);
        while(l<=r && y+(1<<a[r])<=x)y+=(1<<a[r--]);
    }
    ans=x*y;
    cout<<ans<<'\n';
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
