#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n,k;
int f[200010];
void solve() {
    cin>>n>>k;
    int x,ans=0;
    for(int i=1;i<=n;i++)f[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        f[i]=1^f[max(0,i-k-1)];
        if(x&1)
            ans ^= f[i]^f[i-1];
    }
    if(ans==0)
        cout<<"Bob\n";
    else
        cout<<"Alice\n";
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
