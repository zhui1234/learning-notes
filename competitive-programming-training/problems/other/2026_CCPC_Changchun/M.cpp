#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N=8010,M=1000010;
int n,m;
int a[N],b[M];
i64 ans;
void query(int l,int r)
{
    int Gcd=0;
    while(l>=1 && r<=n)
    {
        Gcd=gcd(Gcd,abs(a[r++]-a[l--]));
        if(Gcd==1)break;
        ans+=b[Gcd];
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=2;i<=m;i++)
        for(int j=i;j<=m;j+=i)
            b[j]++;
    b[0]=m-1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
    {
        query(i-1,i+1);
        query(i,i+1);
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
