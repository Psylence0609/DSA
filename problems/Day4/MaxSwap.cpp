#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMax(vector<int> n, int l)
{
    int max = 0, maxpos = 0;
    for (int i = n.size() - 1; i >= l; i--)
    {
        if (n[i] > max)
        {
            max = n[i];
            maxpos = i;
            // cout << "maxpos: " << maxpos << "  max  " << max << endl;
        }
    }
    return make_pair(max, maxpos);
}

int maximumSwap(int num)
{
    int temp = num;
    vector<int> n;
    while (num)
    {
        n.push_back(num % 10);
        num /= 10;
    }
    reverse(n.begin(), n.end());
    int j = 0;
    while (true)
    {
        if (j == n.size() - 1)
            return temp;
        pair<int, int> max_info = findMax(n, j);
        int maxpos = max_info.second;
        int max = max_info.first;
        if (max == n[j])
        {
            j++;
            continue;
        }
        if (j != maxpos)
        {
            // cout << "swap " << j << " " << maxpos << endl;
            int temp = n[j];
            n[j] = n[maxpos];
            n[maxpos] = temp;
            break;
        }
        j++;
    }
    // for (int i = 0; i < n.size(); i++)
    //     cout << n[i];
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < n.size(); i++)
    {
        ans = ans * 10 + n[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << maximumSwap(n);
}