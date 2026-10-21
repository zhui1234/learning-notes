#include <iostream>
#include <cstring>
using namespace std;

const int N = 500001;
int n, a[N], b[N];
long long ans;
void merge_sort(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
        {
            b[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = b[i], b[i] = 0;
}

int main()
{
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    printf("%lld", ans);
    return 0;
}