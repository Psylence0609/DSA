//Given denominations of coins and the target amount N.
//What is the minimum possible number of coins

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int t;
    cin >> N >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
        cin >> arr[i];
    int dp[N + 1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
        dp[i] = 1e9;
    for (int i = 1; i <= N; i++)
    {
        for (int x : arr)
        {
            if (i - x >= 0)
                dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    cout << dp[N];
}

/**
for(int i=0;i<number of denominations;i++)
{
    MN=min(dp[N-a[i]]+1,MN)
}
return MN
**/