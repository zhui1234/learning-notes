#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
string s;
map<char,int>p;
void solve() {
    cin>>n>>s;
    int sum[30];
    for(int i=0;i<26;i++)
        p[i+'a']=i,sum[i]=0;
    for(int l=0;l<n/2;l++)
    {
        int r=n-l-1;
        if(p[s[l]] != p[s[r]])
        {
            if(p[s[l]]>p[s[r]])swap(s[l],s[r]);
            sum[p[s[l]]+1]++,sum[p[s[r]]+1]--;
            p[s[r]]=p[s[l]];
        }
    }
    int ans=0;
    for(int i=0;i<26;i++)
    {
        if(i)sum[i]+=sum[i-1];
        if(sum[i])ans++;
    }
    cout<<ans<<'\n';
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
