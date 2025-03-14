#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    vector<int> a;
    for (int i = 0; i <= r; i++)
        a.push_back(arr[i]);
    sort(a.begin(), a.end());
    return a[k - 1];
}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int k = 3;
    cout << kthSmallest(arr, 0, 5, k);
    return 0;
}