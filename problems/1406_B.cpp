#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, a[120000];

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int l = 0, r = n - 1;
        long long int maxx = a[n - 1] * a[0] * a[1] * a[2] * a[3];
        maxx = max(a[n - 1] * a[n - 2] * a[n - 3] * a[0] * a[1], maxx);
        maxx = max(maxx, a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]);
        printf("%lld\n", maxx);
    }
}