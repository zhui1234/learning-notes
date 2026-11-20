#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=1010;
const string S="RYGB";
int n;
struct card
{
    int x;
    char c;
};
vector<card>a;

bool pd()
{
    for(int k=0;k<3;k++)
    {
        int cnt=0;
        for(int i=k*n;i<4*n && cnt<n;i++)
        {
            if(a[i].c == S[k])
            {
                for(int j=i-1;j>=cnt+k*n;j--)
                    if(a[j].c == a[j+1].c || a[j].x == a[j+1].x)
                        swap(a[j],a[j+1]);
                    else
                        return 0;
                cnt++;
            }
        }
    }/*
    for(int i=0;i<n*4;i++)
        cout<<a[i].x<<' '<<a[i].c<<'\n';*/
    return 1;
}

void solve()
{
    cin>>n;
    int x;
    char c;
    a.clear();
    for(int i=1;i<=n*4;i++)
    {
        cin>>x>>c;
        a.push_back({x,c});
    }
    cout<<(pd()?"Yes\n":"No\n");
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
