#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
int a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    i64 sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)sum+=a[i];
        else
        {
            if(i==n)sum+=a[i];
            else
            {
                if(a[i+1]+a[i]<=0)sum-=a[i]+a[i+1],i++;
                else sum+=a[i];
            }
        }
    }
    cout<<sum<<'\n';
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
