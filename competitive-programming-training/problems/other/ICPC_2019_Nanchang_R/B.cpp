#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
vector<int>g[20],a[20];
int m[20];
int use[20];
int ans;
bool pd(int x)
{
    for(int i:a[x])
        if(use[i])
            return 0;
    return 1;
}
int Pow(int x,int y)
{
    if(y==1)return x;
    return x*x;
}
void ss(int x,int y)
{
    if(x==n)
    {
        ans=min(ans,y);
        return;
    }
    for(int i:g[x])
        if(pd(i))
        {
            use[i]++;
            if(use[i]==1)
                ss(x+1,y+m[i]);
            else
                ss(x+1,y+Pow(m[i],use[i]-1)*(m[i]-1));
            use[i]--;
        }
}

void solve()
{
    cin>>n;
    char c;
    for(int i=0;i<n;i++)
        g[i].clear(),a[i].clear();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>c;
            if(c=='1')g[j].push_back(i);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>c;
            if(c=='1')a[j].push_back(i);
        }
    for(int i=0;i<n;i++)cin>>m[i];
    ans=0x7fffffff;
    ss(0,0);
    if(ans!=0x7fffffff)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
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
