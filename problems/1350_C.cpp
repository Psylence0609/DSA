/**
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int LCM(int a, int b)
{
    return (b * a) / gcd(a, b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    set<int> t;
    for (auto it1 = a.begin(); it1 < a.end() - 1; it1++)
    {
        for (auto it2 = it1 + 1; it2 < a.end(); it2++)
        {
            int lcm = LCM(*it1, *it2);
            t.insert(lcm);
        }
    }
    vector<int> v(t.begin(), t.end());
    int ans = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        ans = gcd(ans, v[i]);
    }
    cout << ans;
}
**/

//Better solution

#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) { return (a * b) / __gcd(a, b); }

int main()
{
    long long n, ans = 0;
    cin >> n;
    vector<long long> a(n), pregcd(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    pregcd[n - 2] = a[n - 1];
    for (int i = n - 3; i >= 0; i--)
        pregcd[i] = __gcd(pregcd[i + 1], a[i + 1]);

    for (int i = 0; i < n - 1; i++)
        pregcd[i] = lcm(pregcd[i], a[i]);

    for (int i = 0; i < n - 1; i++)
        ans = __gcd(ans, pregcd[i]);
    cout << ans << endl;
}