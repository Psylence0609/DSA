#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    queue<pair<int, int>> que;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                que.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    int time = 0;
    cout << "check" << endl;
    for (auto c : visited)
    {
        for (auto e : c)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    while (!que.empty())
    {
        int r = que.size();
        for (int k = 0; k < r; k++)
        {
            auto z = que.front();
            que.pop();
            int x = z.first, y = z.second;
            cout << x << " " << y << endl;
            if (x > 0 && grid[x - 1][y] == 1 && visited[x - 1][y] == 0)
            {
                que.push({x - 1, y});
                visited[x - 1][y] = 1;
            }
            if (x < n - 1 && grid[x + 1][y] == 1 && visited[x + 1][y] == 0)
            {
                que.push({x + 1, y});
                visited[x + 1][y] = 1;
            }
            if (y > 0 && grid[x][y - 1] == 1 && visited[x][y - 1] == 0)
            {
                que.push({x, y - 1});
                visited[x][y - 1] = 1;
            }
            if (y < m - 1 && grid[x][y + 1] == 1 && visited[x][y + 1] == 0)
            {
                que.push({x, y + 1});
                visited[x][y + 1] = 1;
            }
        }
        time++;
    }
    return time - 1;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1, 1, 2, 1, 2, 0, 2},
                                {1, 2, 1, 1, 2, 1, 1, 2, 2},
                                {2, 2, 1, 2, 2, 1, 1, 2, 1},
                                {1, 0, 2, 0, 1, 2, 2, 1, 0},
                                {2, 0, 0, 2, 2, 2, 2, 0, 2},
                                {2, 1, 1, 1, 2, 0, 2, 1, 2},
                                {2, 2, 1, 1, 0, 0, 1, 2, 2},
                                {0, 2, 0, 2, 2, 2, 2, 2, 1},
                                {2, 0, 2, 0, 1, 2, 2, 2, 2},
                                {1, 1, 1, 2, 0, 1, 2, 2, 2}};
    cout << orangesRotting(grid);
}