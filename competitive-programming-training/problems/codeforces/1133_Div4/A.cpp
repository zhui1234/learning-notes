#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int a[3];
void solve() {
    int sum=0;
    for(int i=0;i<3;i++)cin>>a[i],sum+=a[i];
    sort(a,a+3);
    if(sum%3)
    {
        cout<<"NO\n";
        return;
    }
    sum/=3;
    if(a[0]==sum-1 && a[2]==sum+1)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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
