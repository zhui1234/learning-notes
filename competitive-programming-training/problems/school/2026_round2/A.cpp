#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int y,k=1;
    cin>>y;
    if(y>=2019)k++;
    if(y==2020 || y==2021)k--;
    if(y==2026)k+=2;
    cout<<k<<endl;
    if(y>=2005)
    {
        cout<<"ICPC Regional\n";
    }
    if(y>=2019 && y!=2020 && y!=2021)
    {
        cout<<"ICPC Qual\n";
    }
    if(y==2026)
    {
        cout<<"School Regional\n";
        cout<<"School Qual\n";
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
