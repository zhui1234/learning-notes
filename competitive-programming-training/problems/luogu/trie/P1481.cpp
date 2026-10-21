#include <iostream>
#include <cstring>
using namespace std;

const int N = 150001;
int trie[N][26], tot, tag[N];
int n, ans;
char s[80];
int insert()
{
    scanf("%s", s);
    int len = strlen(s);
    int p = 0, num = 0;
    for (int i = 0; i < len; i++)
    {
        int digit = s[i] - 'a';
        if (!trie[p][digit]) trie[p][digit] = ++tot;
        if (tag[p]) num++;
        p = trie[p][digit];
    }
    tag[p] = 1;
    return num + 1;
}

int main()
{
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, insert());
    }
    printf("%d", ans);
    return 0;
}