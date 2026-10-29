#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=410;
int Tnow;
int n,k,L,E,T;
int route[N][2];
int r1,d1,t1;
int r2,d2,t2,d3;
int hp1,hp2,def;
struct tower
{
    int type,x,y,t;
}t[N];
struct enemy
{
    int type,t;
    int hp;
    int burn;//0: 未点燃 >0: 点燃时间
    int status;//0: 存活 1: 死亡 2: 抵达
};
string type;
int Pow(int x)
{
    return x*x;
}
void solve()
{
    cin>>n>>k>>L>>E>>T;
    for(int i=1;i<=L;i++)cin>>route[i][0]>>route[i][1];
    cin>>r1>>d1>>t1>>r2>>d2>>t2>>d3;
    cin>>hp1>>hp2>>def;
    for(int i=1;i<=k;i++)cin>>t[i].type>>t[i].x>>t[i].y,t[i].t=0;
    cin>>type;
    vector<enemy>e;
    for(int i=1;i<=T;i++)
    {
        if(i<=E)
        {
            int e_type=type[i-1]-'0';
            e.push_back({e_type,i,e_type==1?hp1:hp2,0,0});
        }
        for(int l=1;l<=k;l++)
        {
            if(t[l].type==1 && t[l].t && i<t[l].t+t1)continue;
            int target=0,dist=0x7fffffff;
            for(size_t j=0;j<e.size();j++)
            {
                if(e[j].status)continue;
                int now_dist=Pow(t[l].x-route[i-e[j].t+1][0])+Pow(t[l].y-route[i-e[j].t+1][1]);
                if(now_dist<=dist && (!target || (target && e[j].t<e[target].t)))
                    target= j,dist=now_dist;
            }
            if(t[l].type==1 && dist<=Pow(r1))
            {
                t[l].t=i;
                if(e[target].type==1)e[target].hp-=d1;
                else e[target].hp-=max(1,d1-def);
            }
            if(t[l].type==2 && dist<=Pow(r2))
            {
                e[target].burn=i;
                if(e[target].type==1)e[target].hp-=d2;
                else e[target].hp-=max(1,d2-def);
            }
        }
        for(size_t j=0;j<e.size();j++)
        {
            if(e[j].status)continue;
            if(e[j].burn && e[j].burn!=i && e[j].burn+t2<=i)
                e[j].hp-=d3;
            if(e[j].hp<0)
                e[j].status=1,e[j].t=i-e[j].t+1;
            if(e[j].hp>0 && i-e[j].t+1==L)
                e[j].status=2;
        }
    }
    cout<<"Case #"<<(++Tnow)<<":\n";
    for(size_t j=0;j<e.size();j++)
    {
        if(e[j].status==2)cout<<"Arrive with "<<e[j].hp<<" HP(s).\n";
        if(e[j].status==1)cout<<"Be killed in the "<<e[j].t<<"-th frame at ("<<route[e[j].t-j][0]<<","<<route[e[j].t-j][1]<<").\n";
        if(e[j].status==0)cout<<"Be alive at ("<<route[min(L,T)-e[j].t+1][0]<<","<<route[min(L,T)-e[j].t+1][1]<<") with "<<e[j].hp<<" HP(s).\n";
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

    int Tcase = 1;
    cin>>Tcase;
    while (Tcase--) solve();
    return 0;
}
