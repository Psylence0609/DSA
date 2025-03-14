#include <bits/stdc++.h>
using namespace std;

int maxDistToClosest(vector<int> &seats)
{
    vector<int> empty;
    int count = 0;
    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i])
        {
            empty.push_back(count);
            count = 0;
            continue;
        }
        count++;
    }

    empty.push_back(count);

    for (int i = 1; i < empty.size() - 1; i++)
    {
        if (empty[i] % 2)
            empty[i] = empty[i] / 2 + 1;
        else
            empty[i] = empty[i] / 2;
    }
    int max = empty[0];
    for (int i = 1; i < empty.size(); i++)
    {
        if (empty[i] > max)
            max = empty[i];
    }
    return max;
}

int main()
{
    vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    cout << maxDistToClosest(seats);
    return 0;
}