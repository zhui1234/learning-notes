#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=200010;
int n,m,k;
i64 a[N],b[N],c[N];
int f[N*3][2],p[N*3][3];
void solve()
{
    cin>>n>>m>>k;
    vector<i64>d;
    for(int i=1;i<=n;i++){cin>>a[i];d.push_back(a[i]);}
    for(int i=1;i<=m;i++){cin>>b[i];d.push_back(b[i]);}
    for(int i=1;i<=k;i++){cin>>c[i];d.push_back(c[i]);}
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    int pos_max=d.size();
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(d.begin(),d.end(),a[i])-d.begin();
        p[pos+1][0]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int pos=lower_bound(d.begin(),d.end(),b[i])-d.begin();
        p[pos+1][1]=1;
    }
    for(int i=1;i<=k;i++)
    {
        int pos=lower_bound(d.begin(),d.end(),c[i])-d.begin();
        p[pos+1][2]=1;
    }
    for(int pos=1;pos<=pos_max;pos++)
    {
        int l=p[pos][0],r=p[pos][1];
        //cout<<l<<' '<<r<<' '<<p[pos][2]<<'\n';
        if(p[pos][2])
        {
            f[pos][0]=max(f[pos-1][0],f[pos-1][1]+r)+l;
            f[pos][1]=max(f[pos-1][1],f[pos-1][0]+l)+r;
        }
        else
        {
            f[pos][0]=f[pos-1][0]+l;
            f[pos][1]=f[pos-1][1]+r;
        }
        //cout<<f[pos][0]<<' '<<f[pos][1]<<'\n';
    }
    cout<<max(f[pos_max][0],f[pos_max][1])<<'\n';
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //reopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--) solve();
    return 0;
}
