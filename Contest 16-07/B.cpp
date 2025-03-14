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
        int cnt = 0;
        for (auto c : s)
        {
            if ((c - '0') % 2 == 1)
                cnt++;
        }
        if (cnt <= 1)
        {
            cout << -1 << endl;
            continue;
        }
        cnt = 0;
        for (auto c : s)
        {
            if ((c - '0') % 2 == 1)
            {
                cout << c;
                cnt++;
            }
            if (cnt == 2)
                break;
        }
        cout << endl;
    }
    return 0;
}