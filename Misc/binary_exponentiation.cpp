#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
long long binpow_non_recursive(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long binpow_mod(long long a, long long b, long long m) // similar to pow_mod.cpp
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << binpow_mod(a, b, m);
}