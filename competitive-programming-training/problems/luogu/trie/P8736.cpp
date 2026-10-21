#include <iostream>
#include <cstring>
#include <map>
using namespace std;

const int N = 1000001;
string s, name[N], ans[N];
int num;
int st[N], top, maxx;
int find(int x)
{
    int l = 0, r = top;
    int pos;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (name[st[mid]] < name[x])
            pos = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return pos;
}

int main()
{
    // freopen("test.in", "r", stdin);
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            name[++num] += s[i];
        else
            name[num] += s[i];
    }
    for (int i = 1; i <= num; i++)
    {
        int pos = find(i) + 1;
        st[pos] = i;
        ans[pos] = ans[pos - 1] + name[i];
        top = max(top, pos);
        maxx = max(maxx, pos);
    }
    cout << ans[maxx];
    return 0;
}