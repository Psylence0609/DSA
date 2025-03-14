#include <bits/stdc++.h>
using namespace std;

int lcsubstring(int m, int n, int a[], int b[])
{
    int result = 0;
    int dp[m + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return result;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = lcsubstring(m, n, a, b);
    cout << ans;
}