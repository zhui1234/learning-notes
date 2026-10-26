#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=500010;
int n,m;
int d[N],f[N][25];
vector<int>to[N];
queue<int>q;
int ans;
int lca(int u,int v)
{
    if(d[u] < d[v])swap(u,v);

    for(int i=20;i>=0;i--)
        if(d[f[u][i]]>=d[v])
            u=f[u][i];
    if(u==v)
        return u;
    for(int i=20;i>=0;i--)
        if(f[u][i] != f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    return f[u][0];
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) to[i].clear(),d[i]=0,f[i][0]=0;
    for(int i=2;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        to[x].push_back(y),to[y].push_back(x);
    }
    f[1][0]=1;
    d[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v: to[u])
            if(!d[v])
            {
                f[v][0]=u;
                d[v]=d[u]+1;
                q.push(v);
            }
    }
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    ans=d[n]-d[1];
    while(m--)
    {
        int x,y;
        cin>>x;
        y=lca(x,n);
        if(y!=1)
            ans=max(ans,d[x]+d[n]-2*d[y]+1);
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
