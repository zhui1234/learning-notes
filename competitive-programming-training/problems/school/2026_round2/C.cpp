#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
map<string,int>color;
int s1,s2[5],s3[5];

void solve()
{
    int n,ans=0;
    string c,s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c>>s;
        if(s=="Socks")
        {
            s1++;
            continue;
        }
        if(s=="T-shirt")
        {
            s2[color[c]]++;
            continue;
        }
        s3[color[c]]++;
    }
    if(s1)ans++;
    for(int i=0;i<5;i++)
    {
        if(s2[i])
            ans++;

        ans+=(s3[i]+1)/2;
    }
    cout<<ans;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    color["White"]=0;
    color["Black"]=color["Blue"]=color["Gray"]=1;
    color["Yellow"]=2;
    color["Red"]=3;
    color["Green"]=4;
    int T = 1;
    while (T--) solve();
    return 0;
}
