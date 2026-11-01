#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
bool v[100010];
void solve()
{
    cin>>n;
    vector<int>a;
    for(int i=1,x;i<=n;i++){cin>>x;a.push_back(x);v[i-1]=0;}
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int ans=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(v[i])continue;
        int j=a[i];
        while(1)
        {
            if(j&1)j>>=2;
            else j>>=1;
            if(j<a[0])break;
            size_t k=lower_bound(a.begin(),a.end(),j)-a.begin();
            if(k<a.size() && a[k]==j)
            {
                if(v[k])break;
                v[k]=1;
                //cout<<a[i]<<' '<<a[k]<<'\n';
            }
        }
        ans++;
    }
    cout<<ans<<'\n';
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
