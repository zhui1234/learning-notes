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
    i64 cost=0,num=0;
    int l=1,r=n;
    while(l<r)
    {
        while(l<r && a[l+1]==a[l])l++;
        while(l<r && a[r-1]==a[r])r--;
        if(l==r)break;
        if(l<=n-r+1)
        {
            cost+=(i64)(a[l+1]-a[l])*l;
            num+=a[l+1]-a[l];
            l++;
        }
        else
        {
            cost+=(i64)(a[r]-a[r-1])*(n-r+1);
            num+=a[r]-a[r-1];
            r--;
        }
    }
    cout<<cost<<' '<<num<<'\n';
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
