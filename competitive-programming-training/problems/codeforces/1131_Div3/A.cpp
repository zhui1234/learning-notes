#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,m;
char s[110],t[110];
void solve()
{
    cin>>n>>m;
    cin>>s>>t;
    if(n!=m+3){cout<<"NO\n";return;}
    t[m]='s',t[m+1]='i',t[m+2]='x';
    sort(s,s+n);
    sort(t,t+m+3);
    for(int i=0;i<n;i++)
        if(s[i]!=t[i])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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
    cin>>T;
    while (T--) solve();
    return 0;
}
