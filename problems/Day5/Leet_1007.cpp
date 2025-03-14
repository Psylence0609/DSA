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

// int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int a1,a2,a3,a4,a5,a6;
//         int n=tops.size();
//         map<int,pair<int,int> >m;
//         map<int,pair<int,int> >p;

//         for(int i=0;i<tops.size();i++)
//         {
//             if(tops[i]!=bottoms[i])/// if top[i] and bottom[i] is not same then increment total number of elements and individual number
//             {
//                 m[tops[i]].first++;
//                 m[tops[i]].second++;
//                 p[bottoms[i]].first++;
//                 p[bottoms[i]].second++;
//             }
//             else/// otherwise only total number increment;
//             {
//                 m[tops[i]].first++;
//                 p[bottoms[i]].first++;
//             }
//         }

//         int ans=INT_MAX;
//         int item;
//         for(int i=1;i<=6;i++)
//         {
//             ///if top's total number + bottom's individual number ==n or vice versa
//             if(m[i].first+p[i].second==n || m[i].second+p[i].first==n)
//             {
//                 item=max(m[i].first,p[i].first);
//                 ans=min(ans,n-item);
//             }
//         }
//         if(ans!=INT_MAX)
//             return ans;
//         return -1;

//     }