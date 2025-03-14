#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    // write your code here
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> reverse, forw, ans;
    for (int i = 0; i < n / 2; i++)
        reverse.push_back(nums[n - i - 1]);

    int lim;
    if (n % 2 == 0)
        lim = n / 2;
    else
        lim = n / 2 + 1;
    for (int i = 0; i < lim; i++)
        forw.push_back(nums[i]);
    int j = 0;
    for (; j < reverse.size(); j++)
    {
        ans.push_back(forw[j]);
        ans.push_back(reverse[j]);
    }
    // cout << j << endl;
    if (n % 2 != 0)
        ans.push_back(forw[n / 2]);
    for (auto k : ans)
        cout << k << " ";
}

int main()
{
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    wiggleSort(nums);
    return 0;
}