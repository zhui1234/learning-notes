#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
map<char,int>p;
char q[4];
int n;
int sum[4];
int calc(int M,int d,int h,int m,int s)
{
    int t=0;
    if(M>=7)t+=30*24*3600;
    if(M>=8)t+=31*24*3600;
    t+=(d-1)*24*3600;
    t+=h*3600;
    t+=m*60;
    t+=s;
    return t;
}

void solve()
{
    scanf("%d",&n);
    int M,d,h,m,s;
    int t,lt=0;
    char a,la;
    for(int i=1;i<=n;i++)
    {
        scanf("%2d.%2d %2d:%2d:%2d %c",&M,&d,&h,&m,&s,&a);
        t=calc(M,d,h,m,s);
        if(i>1)
            sum[p[la]]+=t-lt;
        lt=t;
        la=a;
    }
    sum[p[la]]+=92*24*3600-lt;
    for(int i=0;i<4;i++)
        printf("%c %2d %02d:%02d:%02d\n",q[i],sum[i]/86400,sum[i]%86400/3600,sum[i]%86400%3600/60,sum[i]%86400%3600%60);
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    p['S']=0,p['W']=1,p['T']=2,p['R']=3;
    q[0]='S',q[1]='W',q[2]='T',q[3]='R';
    int T = 1;
    while (T--) solve();
    return 0;
}
