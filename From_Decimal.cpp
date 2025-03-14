#include <bits/stdc++.h>

using namespace std;

int fromDecimal(int n, int b)
{
    int result = 0, multiplier = 1;
    while (n > 0)
    {
        result += n % b * multiplier;
        multiplier *= 10;
        n /= b;
    }
    return result;
}

string stringDecimal(int n, int b) //upto base 20
{
    string chars = "0123456789ABCDEFGHI";
    string result = "";
    while (n > 0)
    {
        result = chars[n % b] + result;
        n /= b;
    }
    return result;
}

int main()
{
    int n, b;
    cin >> n >> b;
    if (b < 11)
    {
        int decimal = fromDecimal(n, b);
        cout << decimal;
    }
    else
    {
        string decimal = stringDecimal(n, b);
        cout << decimal;
    }
}
