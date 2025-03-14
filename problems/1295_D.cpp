#include <bits/stdc++.h>
using namespace std;
long long int phi(long long int n)
{
    long long int result = n;
    for (long long int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int a, m;
        cin >> a >> m;
        long long int g = __gcd(a, m);
        long long int ans = phi(m / g);
        cout << ans << endl;
    }
}