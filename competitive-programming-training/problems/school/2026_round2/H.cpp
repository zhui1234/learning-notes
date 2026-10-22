#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n,a;
priority_queue<int,vector<int>,less<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(q1.empty() || a<q1.top())
        {
            q1.push(a);
            if(q1.size() > q2.size()+1)
            {
                q2.push(q1.top());
                q1.pop();
            }
        }
        else
        {
            q2.push(a);
            if(q1.size() < q2.size())
            {
                q1.push(q2.top());
                q2.pop();
            }
        }
        if(i&1)
        {
            cout<<q1.top()*2<<' ';
        }
        else
        {
            cout<<q1.top()+q2.top()<<' ';
        }
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
