#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<bool> isprime(32000);

bool Prime(int n)
{
    for (int i = 0; primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
            return false;
    }
    return true;
}

int main()
{

    for (int i = 2; i < 32000; i++)
    {
        if (!isprime[i])
        {
            for (int j = 2; i * j < 32000; j++)
                isprime[i * j] = true;
        }
        primes.push_back(i);
    }

    int n;
    cin >> n;

    if (Prime(n))
    {
        cout << 1 << endl;
        cout << n;
        return 0;
    }

    if (Prime(n - 2))
    {
        cout << 2 << endl;
        cout << 2 << " " << n - 2;
        return 0;
    }

    cout << 3 << endl;

    for (int i = n; i >= 2; i--)
    {
        if (Prime(i))
        {
            cout << i << " ";
            n -= i;
            break;
        }
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (Prime(i) && Prime(n - i))
        {
            cout << i << " " << n - i;
            break;
        }
    }
    return 0;
}