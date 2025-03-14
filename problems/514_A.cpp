#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int n;
    cin >> n;
    int r = int(log10(n) + 1);
    unsigned long long int ans = 0;
    for (int i = r; i > 0; i--)
    {
        unsigned long long int digit = n / round(pow(10, i - 1));
        if (i == r)
        {
            if (digit == 9 || digit < 5)
                ans = digit * pow(10, i - 1);
            else
                ans = (9 - digit) * pow(10, i - 1);
            n = n % (unsigned long long int)round(pow(10, i - 1));
            cout << digit << " " << ans << " " << n << endl;
            continue;
        }
        else
        {
            if (digit < 5)
                ans += digit * round(pow(10, i - 1));
            else
                ans += (9 - digit) * round(pow(10, i - 1));
        }
        n = n % (unsigned long long int)round(pow(10, i - 1));
        cout << digit << " " << ans << " " << n << endl;
    }
    cout << ans;
}

/**
//Correct solution
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    cin >> x;

    for (auto &digit : x)
    {
        if (digit > '4')
            digit = '9' - digit + '0';
    }

    if (x.front() == '0')
        x.front() = '9';
    cout << x << endl;
    return 0;
}
**/