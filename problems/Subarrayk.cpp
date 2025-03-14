#include <bits/stdc++.h>
using namespace std;

// Function that counts the subarrays
// with sum of its elements as its length
int count(int arr[], int N, int k)
{
    vector<int> darr(N);
    for (int i = 0; i < N; i++)
        darr[i] = arr[i];
    for (int i = 0; i < N; i++)
        darr[i] = darr[i] - (double)(1 / k);

    int p[N];
    p[0] = darr[0];

    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] + darr[i];
    map<int, double> mp;
    int answer = 0;
    mp[0]++;
    for (int i = 0; i < N; i++)
    {
        answer += mp[p[i]];
        mp[p[i]]++;
    }
    return answer;
}

// Driver Code
int main()
{
    // Given array arr[]
    int arr[] = {2, -1, 3, 0, 1, 2, 1};
    int N = sizeof arr / sizeof arr[0];

    // Function call
    cout << count(arr, N, 2);
    return 0;
}