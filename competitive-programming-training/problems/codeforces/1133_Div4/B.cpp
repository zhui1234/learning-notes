#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
string s;
void solve() {
    cin>>n>>s;
    int ans=0;
    if(s[0]=='B')ans++;
    for(int i=1;i<n;i++)
        if(s[i]==s[i-1])
            ans++;
    cout<<ans<<endl;
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
