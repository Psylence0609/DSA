#include <bits/stdc++.h>
using namespace std;

int input[1000][1000];
int dp[1000][1000][2] = {1000000000};
char d[1000][1000][2] = {'\0'};

int factor(int x, int k)
{
    int ans = 0;
    while (x >= 0 && x % k == 0)
    {
        ans++;
        x /= k;
    }
    return ans;
}

void print(int i, int j, int k)
{
    if ((i >= 0) && (j >= 0))
    {
        if (d[i][j][k] == 'D')
        {
            print(i - 1, j, k);
        }
        else
        {
            print(i, j - 1, k);
        }
        if (d[i][j][k] != '\0')
        {
            cout << d[i][j][k];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    bool zero = false;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
            if (input[i][j] == 0)
            {
                zero = true;
                input[i][j] = 10;
                x = i;
                y = j;
            }
        }
    }

    dp[0][0][0] = factor(input[0][0], 2);
    dp[0][0][1] = factor(input[0][0], 5);

    for (int i = 1; i < n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + factor(input[i][0], 2);
        dp[i][0][1] = dp[i - 1][0][1] + factor(input[i][0], 5);
        dp[0][i][0] = dp[0][i - 1][0] + factor(input[0][i], 2);
        dp[0][i][1] = dp[0][i - 1][1] + factor(input[0][i], 5);
        d[i][0][0] = 'D';
        d[i][0][1] = 'D';
        d[0][i][0] = 'R';
        d[0][i][1] = 'R';
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int f2 = factor(input[i][j], 2);
            int f5 = factor(input[i][j], 5);

            if (dp[i - 1][j][0] < dp[i][j - 1][0])
            {
                dp[i][j][0] = dp[i - 1][j][0] + f2;
                d[i][j][0] = 'D';
            }
            else
            {
                dp[i][j][0] = dp[i][j - 1][0] + f2;
                d[i][j][0] = 'R';
            }

            if (dp[i - 1][j][1] < dp[i][j - 1][1])
            {
                dp[i][j][1] = dp[i - 1][j][1] + f5;
                d[i][j][1] = 'D';
            }
            else
            {
                dp[i][j][1] = dp[i][j - 1][1] + f5;
                d[i][j][1] = 'R';
            }
        }
    }

    int f = min(dp[n - 1][n - 1][0], dp[n - 1][n - 1][1]);
    int k = 0;
    if (dp[n - 1][n - 1][0] > dp[n - 1][n - 1][1])
        k = 1;

    if (zero && f > 0)
    {
        cout << 1 << endl;
        for (int i = 0; i < x; i++)
            cout << "D";
        for (int i = 0; i < n - 1; i++)
            cout << "R";
        for (int i = 0; i < n - x - 1; i++)
            cout << "D";
    }
    else
    {
        cout << f << endl;
        print(n - 1, n - 1, k);
    }
    // cout << endl;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << d[i][j][0];
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 1; j < n; j++)
    //         cout << d[i][j][0];
    //     cout << endl;
    // }
}