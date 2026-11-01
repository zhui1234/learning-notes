#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;
void solve()
{
    scanf("%d",&n);

    i64 x,y;
    printf("? %d %d\n",0,n);
    fflush(stdout);
    scanf("%lld",&x);

    printf("? %d %d\n",0,0);
    fflush(stdout);
    scanf("%lld",&y);

    printf("! %lld %lld\n",(x+y-n)/2,(y-x+n)/2);
    fflush(stdout);
}

int main()
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int T = 1;
    while (T--) solve();
    return 0;
}
