#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
bool p[10];
int n,num1,num2;

void pd(int x)
{
    bool v=0;
    while(x)
    {
        int y=x%10;
        if(!p[y])return;
        if(y == 3 || y == 7)v=1;
        x/=10;
    }
    num2++;
    if(!v)num1++;
}
void solve()
{
    num1=num2=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        pd(i);
    cout<<num1<<' '<<num2<<endl;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p[0]=p[1]=p[5]=p[8]=p[3]=p[7]=1;

    int T = 1;
    while (T--) solve();
    return 0;
}
