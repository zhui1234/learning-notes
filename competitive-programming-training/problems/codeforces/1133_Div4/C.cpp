#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
void solve() {
    cin>>n;
    vector<int>a,b,c;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
        if(a[i]==a[i-1])
        {
            c.push_back(a[i]);
            if(b.empty() || b.back() != a[i])
                b.push_back(a[i]);
        }
    /*
    for(int bb:b)cout<<bb<<' ';
    cout<<'\n';
    for(int cc:c)cout<<cc<<' ';
    cout<<'\n';*/
    a.erase(unique(a.begin(),a.end()),a.end());
    //cout<<a.size()<<' '<<b.size()<<'\n';
    int ans=a.size()+b.size();
    for(int i=a.size()-1;i>=0;i--)
        c.push_back(a[i]);

    cout<<ans<<'\n';
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<' ';
    cout<<'\n';
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
