#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,m;
string s[100010],t[100010];
void ss(int l,int r)
{

}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1);
    //for(int i=1;i<=n;i++)cout<<s[i]<<'\n';
    for(int i=1;i<=n;i++)
        if(s[i]!=s[i-1])
            t[++m]==s[i];
    ss(1,m);
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
