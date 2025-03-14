#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f[n];
    for (int i = 0; i < n; i++)
        cin >> f[i];

    for (int i = 0; i < n; i++)
    {
        if (f[f[i] - 1] == i + 1)
            continue;
        if (f[f[f[i] - 1] - 1] == i + 1)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}