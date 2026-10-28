#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,c,a[200010];

void solve()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int j=1,k;
    i64 last,num=0;
    for(int i=1;a[i]+c<=a[n];i++)
    {
        if(i>1 && a[i]==a[i-1])
        {
            num+=last;
            continue;
        }
        k=lower_bound(a+j,a+n+1,a[i]+c)-a;
        j=upper_bound(a+j,a+n+1,a[i]+c)-a;
        last=j-k;
        num+=j-k;
    }
    cout << num;
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
