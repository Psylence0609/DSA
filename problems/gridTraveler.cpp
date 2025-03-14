#include <bits/stdc++.h>
using namespace std;

int gridTraveler(int m, int n, vector<vector<int>> &memo)
{
    if (m == -1 || n == -1)
        return 0;
    if (m == 0 && n == 0)
        return 1;
    if (memo[m][n] > -1)
        return memo[m][n];
    memo[m][n] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
    return memo[m][n];
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> memo(m, vector<int>(n, -1));
    gridTraveler(m - 1, n - 1, memo);
    cout << memo[m - 1][n - 1];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << memo[i][j];
        }
    }
}