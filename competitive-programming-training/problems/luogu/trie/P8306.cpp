#include <iostream>
#include <cstring>
using namespace std;

const int N = 3000010;
int t, n, q;
int trie[N][70], cnt[N], tot;
string s;
int Digit(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return c - 'a' + 36;
}
void insert(string& s)
{
    int len = s.size();
    int p = 1;
    for (int i = 0; i < len; i++)
    {
        int digit = Digit(s[i]);
        if (!trie[p][digit]) trie[p][digit] = ++tot;
        p = trie[p][digit];
        cnt[p]++;
    }
}
int search(string& s)
{
    int len = s.size();
    int p = 1;
    for (int i = 0; i < len; i++)
    {
        int digit = Digit(s[i]);
        if (!trie[p][digit]) return 0;
        p = trie[p][digit];
    }
    return cnt[p];
}
void solve()
{
    scanf("%d %d\n", &n, &q);

    for (int i = 1; i <= tot; i++)
    {
        cnt[i] = 0;
        for (int j = 0; j < 70; j++) trie[i][j] = 0;
    }
    tot = 1;
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        insert(s);
    }
    for (int i = 1; i <= q; i++)
    {
        getline(cin, s);
        printf("%d\n", search(s));
    }
}

int main()
{
    // freopen("P8306_2.in", "r", stdin);
    for (cin >> t; t; t--) solve();
    return 0;
}