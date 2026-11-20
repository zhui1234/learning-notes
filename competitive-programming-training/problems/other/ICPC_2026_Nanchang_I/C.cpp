#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N=210,INF=40010;
int n,m,k,q,w;
struct mat
{
    int size;
    vector<vector<int>>a;

    mat(int size,bool ident,int init):size(size),a(size,vector<int>(size,init))
    {
        if(ident)
            for(int i=0;i<size;i++)
                a[i][i]=0;
    }
    mat operator *(const mat& B) const
    {
        mat C(size,0,INF);
        for(int i=0;i<size;i++)
            for(int k=0;k<size;k++)
            {
                int x=a[i][k];
                if(x!=INF)
                    for(int j=0;j<size;j++)
                    {
                        int y=B.a[k][j];
                        if(y!=INF)
                            C.a[i][j]=min(C.a[i][j],max(x,y));
                    }
            }
        return C;
    }
};
mat pow(mat A,int x)
{
    mat res(n,1,INF);
    while(x)
    {
        if(x&1)res=res*A;
        A=A*A;
        x>>=1;
    }
    return res;
}

void solve()
{
    cin>>n>>m;
    mat date(n,0,INF);
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        date.a[u-1][v-1]=0;
    }
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v;
        date.a[u-1][v-1]=min(date.a[u-1][v-1],i);
    }
    cin>>q>>w;
    mat ans=pow(date,w);
    while(q--)
    {
        cin>>u>>v;
        u--,v--;
        int time=ans.a[u][v];
        if(time == INF)
            cout<<-1<<'\n';
        else
            cout<<time<<'\n';
    }
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
    while (T--) solve();
    return 0;
}
