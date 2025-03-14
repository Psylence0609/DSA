#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int> tops, vector<int> bottoms, int num)
{
    int count = 0;
    for (int i = 0; i < tops.size(); i++)
    {
        if (tops[i] == num)
            continue;
        if (bottoms[i] == num)
            count++;
        else
        {
            return -1;
        }
    }
    return count;
}

pair<int, int> max_num(vector<int> a)
{
    int m = a[0], pos = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > m)
        {
            m = a[i];
            pos = i;
        }
    }
    return make_pair(m, pos);
}

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int n = tops.size();
    vector<int> top_count(6, 0);
    vector<int> bot_count(6, 0);

    for (int i = 0; i < n; i++)
    {
        top_count[tops[i]]++;
        bot_count[bottoms[i]]++;
    }
    pair<int, int> top_mod = max_num(top_count);
    pair<int, int> bot_mod = max_num(bot_count);
    if (top_mod.first > bot_mod.first)
    {
        return find_min(tops, bottoms, top_mod.second + 1);
    }
    else
        return find_min(bottoms, tops, bot_mod.second + 1);
}

int main()
{
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};
    cout << minDominoRotations(tops, bottoms);
}

//