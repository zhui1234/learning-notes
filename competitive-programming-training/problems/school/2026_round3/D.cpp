#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N=100010;
int n;
i64 x;
struct jump
{
    i64 a,b,c,d;
}p[N];
bool cmp(jump x1,jump x2)
{
    return x1.d>x2.d;
}
void solve()
{
    cin>>n>>x;
    i64 sum=0,maxx=-0x7fffffff;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].a>>p[i].b>>p[i].c;
        maxx=max(maxx,p[i].a*p[i].b-p[i].c);
        sum+=p[i].a*(p[i].b-1);
    }
    if(sum>=x)
    {
        cout<<0<<endl;
        return;
    }
    if(maxx<=0)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<(x-sum+maxx-1)/maxx<<endl;
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
