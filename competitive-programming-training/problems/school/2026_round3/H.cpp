#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=1010,M=100010;

int n,m,q;
struct Flare
{
    int a,id;
}f[N];
int g[N];
int match[N],ans;
int head[N],to[M],Next[M],tot;
bool vis[N];
bool cmp(Flare x1,Flare x2)
{
    if(x1.a!=x2.a)return x1.a>x2.a;
    return x1.id<x2.id;
}
bool pd(int u)
{
    for(int i=head[u];i;i=Next[i])
    {
        int v=to[i];
        if(!vis[v])
        {
            vis[v]=1;
            if(!match[v] || pd(match[v]))
            {
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>f[i].a,f[i].id=i;
    sort(f+1,f+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        g[i]=f[i].id;
        //cout<<g[i]<<'\n';
    }
    for(int i=1,u,v;i<=q;i++)
    {
        cin>>u>>v;
        to[++tot]=v,Next[tot]=head[u],head[u]=tot;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)vis[j]=0;
        if(pd(g[i]))
            ans++;
    }
    for(int i=1;i<=m;i++)
        if(match[i])
            cout<<match[i]<<' '<<i<<'\n';
    //cout<<ans;
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
