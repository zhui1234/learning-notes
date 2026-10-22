#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 n,k;
int a[200010];

void solve()
{
    cin>>n>>k;
    i64 sum=k*(k+1)/2;
    i64 num=n/sum;
    n%=sum;
    for(int i=k;i>=1;i--)
    {
        if(n>=i)
        {
            n-=i;
            a[i]++;
        }
    }
    for(int i=1;i<=k;i++)
        cout<<a[i]+num<<' ';
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
