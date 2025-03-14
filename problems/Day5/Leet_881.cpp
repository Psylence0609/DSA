#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1, ans = 0;
    vector<int> check(people.size(), 0);
    while (i < j)
    {
        if (people[i] + people[j] <= limit)
        {
            check[i] = 1;
            check[j] = 1;
            i++;
            j--;
            ans++;
        }
        else
        {
            j--;
        }
    }
    for (int i = 0; i < people.size(); i++)
    {
        // cout << check[i] << " ";
        if (check[i] == 0)
        {
            ans++;
        }
    }
    // cout << endl;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int limit;
    cin >> limit;
    cout << numRescueBoats(a, limit) << endl;
}