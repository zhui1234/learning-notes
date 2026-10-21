#include <iostream>
#include <cstring>
using namespace std;

const int N = 500001;
int trie[N][26], tot, tag[N], vis[N];
int n, m;
char s[80];
void insert()
{
    scanf("%s", s);
    int len = strlen(s);
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int digit = s[i] - 'a';
        if (!trie[p][digit]) trie[p][digit] = ++tot;
        p = trie[p][digit];
    }
    tag[p] = 1;
}
void search()
{
    scanf("%s", s);
    int len = strlen(s);
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int digit = s[i] - 'a';
        if (!trie[p][digit])
        {
            puts("WRONG");
            return;
        }
        p = trie[p][digit];
    }
    if (!tag[p])
        puts("WRONG");
    else
    {
        if (!vis[p])
            puts("OK");
        else
            puts("REPEAT");
        vis[p] = 1;
    }
}

int main()
{
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) insert();
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) search();
    return 0;
}