#include <iostream>
#include <cstring>
using namespace std;

const int N = 50001;
int trie[N][26], tot = 1;
int n, ans;
char s[80];
void insert(char s[])
{
    int len = strlen(s);
    int p = 1;
    for (int i = 0; i < len; i++)
    {
        int digit = s[i] - 'A';
        if (!trie[p][digit]) trie[p][digit] = ++tot;
        p = trie[p][digit];
    }
}

int main()
{
    // freopen("test.in", "r", stdin);
    while (scanf("%s", s) != EOF) insert(s);
    printf("%d", tot);
    return 0;
}