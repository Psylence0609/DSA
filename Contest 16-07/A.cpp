#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            if (s[i] == s[(n - 1) / 2])
                ans++;
            else
                break;
        }
        int p = n % 2 ? 1 : 0;
        cout << 2 * ans - p << endl;
    }
}