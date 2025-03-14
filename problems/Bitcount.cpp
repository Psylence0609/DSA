#include <bits/stdc++.h>
using namespace std;

int bitcount(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> count(32, 0);
    int i = 0;
    while (arr[n - 1] != 0)
    {
        for (int k = 0; k < n; k++)
        {
            int r = arr[k] % 2;
            arr[k] /= 2;
            count[i] += r;
        }
        i++;
    }
    sort(count.begin(), count.end());
    return count[31];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << bitcount(arr);
}