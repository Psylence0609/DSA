#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    vector<pair<int, int>> dp(n, {0, 0});
    return 0;
}
