#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
void solve()
{
    cin>>n;
    if(n&1)
        cout<<(n/2)*(n/2+1)<<endl;
    else
        cout<<n*n/4<<endl;
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
