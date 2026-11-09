#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,k;
int a[200010],b[200010];
void solve()
{
    cin>>n>>k;
    i64 sum=0;
    b[0]=0;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    int cnt=0;
    if(k==n)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        b[++b[0]]=a[i];
        if(1LL*a[i]*(n-i+1)<sum)
        {
            cnt++;
            if(n-cnt==k)
            {
                cout<<"YES\n";
                for(int j=i+1;j<=n;j++)cout<<a[j]<<' ';
                for(int j=b[0];j>=1;j--)cout<<b[j]<<' ';
                cout<<'\n';
                return;
            }
        }
        sum-=a[i];
    }
    cout<<"NO\n";
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
    while (T--)
        solve();
    return 0;
}
