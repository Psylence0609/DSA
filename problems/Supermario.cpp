//Princess peach is hidden at the bottom corner of an mxn prison.
//Mario needs to start at the top left corner. Each room has powerups(+health) or obstacles(-health)
//Find the minimum initial health so that he can survive the prison.
//He can move right or downwards and if health is 0 then he dies.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int prison[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> prison[i][j];
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
    dp[m - 1][n] = dp[m][n - 1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        dp[m][i] = 1e9;
    }
    for (int i = 0; i < m - 1; i++)
    {
        dp[i][n] = 1e9;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - prison[i][j]);
        }
    }
    cout << dp[0][0];
}