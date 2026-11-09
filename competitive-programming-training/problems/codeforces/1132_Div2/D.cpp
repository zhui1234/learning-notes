#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
int prime[100010],tot;
bool p[200010];
void init()
{
    for(int i=2;i<=2e5;i++)
    {
        if(!p[i])
            prime[++tot]=i;
        for(int j=1;j<=tot && i*prime[j]<=2e5;j++)
        {
            p[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x;
        y=lower_bound(prime+1,prime+tot+1,x)-prime;
        cout<<prime[y]<<' ';
    }
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
    init();
    int T = 1;
    cin>>T;
    while (T--) solve();
    return 0;
}
