#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200010;
int t;
int n;
string s;
int st1[N], st2[N];
int top1, top2;
int p[N];
void solve()
{
    cin >> n;
    cin >> s;
    int num = 0, p1 = 0, p2 = 0;
    top1 = top2 = 0;
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (top2)
            {
                p[i] = p[st2[top2]] = 1;
                top2--;
                p1 = 1;
            }
            else
                st1[++top1] = i;
            num++;
        }
        else
        {
            if (top1)
            {
                p[i] = p[st1[top1]] = 2;
                top1--;
                p2 = 1;
            }
            else
                st2[++top2] = i;
            num--;
        }
    }
    if (num)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", p1 + p2);
    if (p1 + p2 == 1)
        for (int i = 0; i < n; i++) printf("1 ");
    else
        for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> t;
    while (t--) solve();
    return 0;
}
