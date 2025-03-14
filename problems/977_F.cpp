#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0, lst = 0;
    map<int, int> dp;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        dp[x] = dp[x - 1] + 1;
        if (ans < dp[x])
        {
            ans = dp[x];
            lst = x;
        }
    }
    //cout << "CHECK" << endl;
    vector<int> result;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == lst)
        {
            result.push_back(i);
            lst--;
        }
    }
    reverse(result.begin(), result.end());
    cout << ans << endl;
    for (auto it : result)
    {
        cout << it + 1 << " ";
    }
}