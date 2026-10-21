#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010;
int t, n;
int p, now, last, head;
void solve()
{
    cin >> n;
    cin >> head;
    p = 0, last = head;
    printf("1");
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        if (now >= last)
        {
            if (!p || (p && now <= head))
            {
                last = now;
                printf("1");
            }
            else
                printf("0");
        }
        else
        {
            if (!p && now <= head)
            {
                p = 1;
                last = now;
                printf("1");
            }
            else
                printf("0");
        }
    }
    printf("\n");
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
