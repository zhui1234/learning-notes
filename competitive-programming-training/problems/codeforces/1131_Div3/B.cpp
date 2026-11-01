#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int x,y,z;
void solve()
{
    cin>>x>>y>>z;
    if(x>=max(y,z))
        for(int i=1;i<=x+y+z;i++)cout<<'P';
    else
        if(y>=max(x,z))
            for(int i=1;i<=x+y+z;i++)cout<<'R';
        else
            for(int i=1;i<=x+y+z;i++)cout<<'S';
    cout<<'\n';
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
