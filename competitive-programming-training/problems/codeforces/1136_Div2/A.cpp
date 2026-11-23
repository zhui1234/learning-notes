#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int x;
void solve()
{
    cin>>x;
    int ans=x;
    for(int a=0;a<=x;a++)
    {
        int now=a,cnt=a,sum=0;
        while(sum<x)
        {
            if(now==0)
            {
                cnt+=x-sum;
                break;
            }
            sum+=now+1;
            now--;
            cnt++;
        }
        ans=min(ans,cnt);
    }
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
