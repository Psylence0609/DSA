#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    int ans;
    cin >> n;
    int multiplier = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        ans += (n[i] - 'A' + 1) * multiplier;
        multiplier *= 26;
    }
    cout << ans;
}