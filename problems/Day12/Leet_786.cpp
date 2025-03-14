#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    vector<pair<double, int>> fractions;
    vector<vector<int>> nums;
    int r = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            double f = arr[i];
            f /= arr[j];
            fractions.push_back(make_pair(f, r));
            vector<int> temp = {arr[i], arr[j]};
            nums.push_back(temp);
            r++;
        }
    }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i][0] << " " << nums[i][1] << endl;
    // }
    sort(fractions.begin(), fractions.end());
    // cout << "check" << endl;
    for (int i = 0; i < fractions.size(); i++)
    {
        cout << fractions[i].first << " " << fractions[i].second << endl;
    }
    return nums[fractions[k - 1].second];
}

int main()
{
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    vector<int> ans = kthSmallestPrimeFraction(arr, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}