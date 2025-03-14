#include <bits/stdc++.h>
using namespace std;

int countTriplet(int arr[], int n)
{
    // Your code goes here
    sort(arr, arr + n);
    int ans = 0;
    cout << 1 << endl;
    for (int i = n - 1; i > 1; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            int sum = arr[l] + arr[r];
            cout << sum << endl;
            if (sum == arr[i])
            {
                ans++;
                break;
            }
            else if (sum > arr[i])
                r--;
            else
                l++;
        }
    }
    return ans;
}

int main()
{
    int n = 4;
    int arr[] = {1, 5, 2, 3};
    cout << countTriplet(arr, n);
}