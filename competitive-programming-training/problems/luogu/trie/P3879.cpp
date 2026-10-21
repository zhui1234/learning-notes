#include <iostream>
#include <cstring>
using namespace std;

const int N = 500001, M = 5010;
int t, n, q;
int trie[N][26], tot;
bool belong[N][1001];
char s[M];
int Digit(char c) { return c - 'a'; }
void insert(int x)
{
    scanf("%s", s);
    int len = strlen(s);
    int p = 1;
    for (int i = 0; i < len; i++)
    {
        int digit = Digit(s[i]);
        if (!trie[p][digit]) trie[p][digit] = ++tot;
        p = trie[p][digit];
    }
    belong[p][x] = 1;
}
void search()
{
    scanf("%s", s);
    int len = strlen(s);
    int p = 1;
    for (int i = 0; i < len; i++)
    {
        int digit = Digit(s[i]);
        if (!trie[p][digit])
        {
            printf("\n");
            return;
        }
        p = trie[p][digit];
    }
    for (int i = 1, pd = 0; i <= t; i++)
        if (belong[p][i])
        {
            if (pd) printf(" ");
            printf("%d", i);
            pd = 1;
        }
    printf("\n");
}
void solve()
{
    scanf("%d\n", &t);
    tot = 1;
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) insert(i);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) search();
}

int main()
{
    // freopen("test.in", "r", stdin);
    solve();
    return 0;
}