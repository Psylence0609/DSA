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

        bool check = false;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            int r = s.size();
            if (r & 1)
            {
                check = true;
                continue;
            }
            int one = 0, zero = 0;
            for (auto c : s)
            {
                if (c == '1')
                    one++;
                else
                    zero++;
            }
            if (one & 1 or zero & 1)
                c1++;
            else
                c2++;
        }
        if (check && c1 % 2 == 0)
            cout << n << endl;
        else
            cout << n - 1 << endl;
    }
    return 0;
}