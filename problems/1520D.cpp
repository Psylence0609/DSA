#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int ans = 0;
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            num -= i;
            ans += mp[num];
            mp[num]++;
        }
        cout << ans << endl;
    }
}