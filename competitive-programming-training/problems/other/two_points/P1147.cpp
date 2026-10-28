#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;

void solve()
{
    cin>>n;
    int l=1,r=4;
    while(r*(r+1)<2*n)r++;
    do
    {
        if((l+r)*(r-l+1)==2*n)
        {
            cout<<l<<' '<<r<<endl;
            l++;
        }
        while((l+r)*(r-l+1)<2*n)r++;
        while((l+r)*(r-l+1)>2*n)l++;
    }while(2*r-1<=n);
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
