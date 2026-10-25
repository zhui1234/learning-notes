#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,m,w[30010];

void solve()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    sort(w+1,w+n+1);
    int i=1,j=n,num=0;
    while(i<=j)
    {
        num++;
        if(i==j || w[i]+w[j]>m)
            j--;
        else
            i++,j--;
    }
    cout << num;
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
    while (T--) solve();
    return 0;
}
