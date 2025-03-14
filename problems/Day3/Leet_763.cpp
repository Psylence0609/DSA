#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s)
{
    int l = s.size();
    string actual = s;
    reverse(s.begin(), s.end());
    map<char, int> position;
    vector<int> ans;
    int count = 0;
    int max = 0;
    // cout << "max count" << endl;
    for (int i = 0; i < l; i++)
    {
        char c = actual[i];
        count += 1;
        if (position.count(c))
        {
            // cout << c << " found" << endl;
            if (i == max)
            {
                ans.push_back(count);
                count = 0;
                max = 0;
            }
        }
        else
        {
            // cout << c << " not found" << endl;
            int r = find(s.begin(), s.end(), c) - s.begin();
            position[c] = l - r - 1;
            if (max < l - r - 1)
                max = l - r - 1;
            if (i == max)
            {
                ans.push_back(count);
                count = 0;
                max = 0;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<int> ans = partitionLabels(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}