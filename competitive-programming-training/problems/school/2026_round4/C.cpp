#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 x;
void solve()
{
    cin>>x;
    for(i64 u=sqrt(x+1);u>=2;u--)
        if((x+1)%u==0)
        {
            i64 v=(x+1)/u;
            cout<<x+2-u-v<<'\n';
            return;
        }
    cout<<"0\n";
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
