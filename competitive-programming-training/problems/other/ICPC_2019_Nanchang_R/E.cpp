#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,m,k;
struct edge
{
    int x,y,z;
}e[500010];
int f[50010],g[50010],u[500010];

bool cmp(edge x1,edge x2)
{
    return x1.z>x2.z;
}
int find(int x)
{
    while(f[x]!=x)
    {
        f[x]=f[f[x]];
        x=f[x];
    }
    return x;
}
int unite(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return 0;
    if(g[fy]>g[fx])swap(fx,fy);
    g[fx]+=g[fy];
    f[fy]=fx;
    return 1;
}
void solve()
{
    int tot=0,cnt=0,num=0;
    i64 ans=0;

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=i,g[i]=1;

    for(int i=1;i<=m;i++)
    {
        int x,y,z,c;
        cin>>x>>y>>z>>c;
        if(!c)num+=unite(x,y),ans+=z;
        else
            e[++tot].x=x,e[tot].y=y,e[tot].z=z,u[tot]=0;
    }
    sort(e+1,e+tot+1,cmp);
    for(int i=1;i<=tot;i++)
        if(unite(e[i].x,e[i].y))
        {
            ans+=e[i].z;
            cnt++;
            num++;
            u[i]=1;
            if(cnt==k || num==n-1)break;
        }
    for(int i=1;i<=tot && cnt<k;i++)
        if(!u[i])
            ans+=e[i].z,cnt++;
        else
            u[i]=0;
    if(num==n-1)
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
