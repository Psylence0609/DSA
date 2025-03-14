#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, c, d, cont = 0;
        cin >> n >> a >> b >> c >> d;
        if ((n * (a + b) >= c - d) && (n * (a - b) <= c + d))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}