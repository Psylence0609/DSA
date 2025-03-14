#include <bits/stdc++.h>
#define ll int

using namespace std;

ll factors(ll a)
{
    ll pc1 = 0;
    for (ll i = 2; i * i <= a; i++)
    {
        while (a % i == 0)
        {
            a /= i;
            pc1++;
        }
    }
    if (a > 1)
    {
        pc1++;
    }
    return pc1;
}
void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (a > b)
        swap(a, b);
    if (k == 1)
    {
        if (b % a == 0 && a < b)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    ll pc1 = factors(a), pc2 = factors(b);
    if (pc1 + pc2 < k)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}