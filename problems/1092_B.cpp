#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int total = 0;
    for (int i = 0, j = 1; i < n - 1; i += 2, j += 2)
    {
        total += a[j] - a[i];
    }
    cout << total;
    return 0;
}