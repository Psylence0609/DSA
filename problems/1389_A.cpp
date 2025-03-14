#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x = -1, y = -1;
        int l, r;
        cin >> l >> r;
        if (2 * l <= r)
        {
            x = l;
            y = 2 * l;
        }
        cout << x << " " << y << endl;
    }
}