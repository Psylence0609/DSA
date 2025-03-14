#include <iostream>

using namespace std;

int main()
{
    int n, m, a, b, price;
    cin >> n;
    cin >> m;
    cin >> a;
    cin >> b;
    if (b / m < a)
    {
        price = (n / m) * b;
        int res = n % m * a;
        if (b < res)
            price += b;
        else
            price += res;
    }
    else
        price = n * a;
    cout << price;
}