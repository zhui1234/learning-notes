#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 l,r;
void solve()
{
    cin>>l>>r;
    int num=r-l+1;
    if(num==1){cout<<l<<'\n';return;}
    if(num==2){cout<<l+r<<'\n';return;}
    if(r&1)
    {
        cout<<r*3-3<<'\n';
    }
    else
    {
        if(num>=4)cout<<max(r*3-6,r*2-1)<<'\n';
        else cout<<r*2-1<<'\n';
    }
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
