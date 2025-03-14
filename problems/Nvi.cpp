#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mn = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                mn = min(mn, abs(v[i] - v[i - j]) + dp[i - j]);
                        }
        }
        dp[i] = mn;
    }
    cout << dp[n - 1] << endl;
}