// Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
// We are given two arrays that represent the arrival and departure times of trains that stop.

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number
// of platforms required
int findPlatform(int arr[], int dep[], int n)
{
    // Store the arrival and departure time
    vector<pair<int, int>> arr2(n);

    for (int i = 0; i < n; i++)
    {
        arr2[i] = {arr[i], dep[i]};
    }

    // Sort arr2 based on arival time
    sort(arr2.begin(), arr2.end());

    priority_queue<int, vector<int>, greater<int>> p;
    int count = 1;
    p.push(arr2[0].second);

    for (int i = 1; i < n; i++)
    {

        // Check if arrival time of current train
        // is less than or equals to depature time
        // of previous train
        if (p.top() >= arr2[i].first)
        {
            count++;
        }
        else
        {
            p.pop();
        }
        p.push(arr2[i].second);
    }

    // Return the number of train required
    return count;
}

// Driver Code
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}