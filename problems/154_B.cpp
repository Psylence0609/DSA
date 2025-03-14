
/**
#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int conflict(set<int> activated, int x)
{
    for (auto it = activated.begin(); it != activated.end(); it++)
    {
        if (GCD(*it, x) != 1)
            return *it;
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> activated;
    while (m--)
    {
        char sign;
        int x;
        cin >> sign >> x;
        if (sign == '+')
        {
            if (find(activated.begin(), activated.end(), x) != activated.end())
            {
                cout << "Already on" << endl;
                continue;
            }
            int j = conflict(activated, x);
            if (j)
                cout << "Conflict with " << j << endl;
            else
            {
                cout << "Success" << endl;
                activated.insert(x);
            }
        }
        else
        {
            if (find(activated.begin(), activated.end(), x) == activated.end())
                cout << "Already off" << endl;
            else
            {
                cout << "Success" << endl;
                activated.erase(x);
            }
        }
    }
}

**/

//Another solution

#include <bits/stdc++.h>

using namespace std;

vector<int> factors(int x, vector<bool> prime)
{
    vector<int> ans;
    for (int p = 2; p * p <= x; p++)
    {
        if (x % p != 0)
            continue;
        if (prime[p])
            ans.push_back(p);
        if (prime[x / p])
            ans.push_back(x / p);
    }

    if (ans.empty())
        ans.push_back(x);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int q = p * p; q <= n; q += p)
                isPrime[q] = 0;
        }
    }

    vector<int> active(n + 1, 0);
    set<int> on;

    while (m--)
    {
        char action;
        int x;
        cin >> action >> x;

        vector<int> factor = factors(x, isPrime);

        if (action == '+')
        {
            if (on.count(x) > 0)
                cout << "Already on" << endl;
            else
            {
                int conflict = 0;
                for (int p = 0; p < factor.size(); p++)
                {
                    if (active[factor[p]] > 0)
                    {
                        conflict = active[factor[p]];
                        break;
                    }
                }
                if (conflict)
                    cout << "Conflict with " << conflict << endl;
                else
                {
                    cout << "Success" << endl;
                    on.insert(x);
                    for (int i = 0; i < factor.size(); i++)
                        active[factor[i]] = x;
                }
            }
        }
        else if (action == '-')
        {
            if (on.count(x) > 0)
            {
                cout << "Success" << endl;
                on.erase(x);
                for (int i = 0; i < factor.size(); i++)
                    active[factor[i]] = 0;
            }
            else
                cout << "Already off" << endl;
        }
    }
    return 0;
}
