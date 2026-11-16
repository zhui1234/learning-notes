#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n,k;
bool v[200010];
void solve()
{
    cin>>n>>k;
    vector<int>a,ans;
    int num=0;
    for(int i=1,x;i<=n;i++)
        cin>>x,a.push_back(x),v[i-1]=0;
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(size_t i=0;i<a.size();i++)
        if(!v[i])
        {
            num++;
            ans.push_back(a[i]);
            for(int j=2;a[i]<=k/j;j++)
            {
                size_t pos=lower_bound(a.begin()+i+1,a.end(),a[i]*j)-a.begin();
                if(pos!=a.size() && a[pos]==a[i]*j)
                    v[pos]=1;
                else
                {
                    cout<<"-1\n";
                    return;
                }
            }
        }
    cout<<num<<'\n';
    for(size_t i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
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
