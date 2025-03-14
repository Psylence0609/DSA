#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> nums)
{
    map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i]) != m.end())
        {
            m[nums[i]]++;
        }
        else
        {
            m[nums[i]] = 1;
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second > nums.size() / 3)
        {
            res.push_back(it->first);
        }
    }
    return res;
}
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ans = majorityElementII(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    return 0;
}