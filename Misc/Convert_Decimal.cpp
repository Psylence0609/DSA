#include <bits/stdc++.h>

using namespace std;

int toDecimal(int n, int b)
{
    int result = 0, multiplier = 1;

    while (n > 0)
    {
        result += n % 10 * multiplier;
        multiplier *= b;
        n /= 10;
    }
    return result;
}

int main()
{
    int n, b;
    cin >> n >> b;
    int decimal = toDecimal(n, b);
    cout << decimal;
}