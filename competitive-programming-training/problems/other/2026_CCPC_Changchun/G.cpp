#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=200010;
int n,m;
string a,b;
bool use[N],vis[N];
int head[N],Next[N<<1],from[N<<1],to[N<<1],tot;
void add(int u,int v)
{
    to[++tot]=v;
    from[tot]=u;
    Next[tot]=head[u];
    head[u]=tot;
}
bool query(int now,int l,int r,int p=0)
{
    if(now==r)
        return 1;
    for(int i=head[now];i;i=Next[i])
    {
        if((i+1)/2==p)continue;
        if(!vis[to[i]])
        {
            vis[to[i]]=1;
            if(query(to[i],l,r)==1)
            {
                use[(i+1)/2]=1;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m>>a>>b;
    for(int i=1;i<=m*2;i++)use[i]=0;
    for(int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    for(int i=0,p=0,q;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if(!p)p=1,q=i+1;
        }
        else
        {
            if(p)
            {
                p=0;
                for(int j=1;j<=n;j++)vis[j]=0;
                if(!query(q,q,i))
                {
                    for(int j=0;j<n;j++)cout<<0;
                    cout<<'\n';
                    return;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
        if(use[i])
        {
            for(int j=1;j<=n;j++)vis[j]=0;
            if(!query(from[i],from[i],to[i],i))
                cout<<1;
            else
                cout<<0;
        }
        else
            cout<<0;
    cout<<'\n';
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
