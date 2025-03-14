#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int r, c;
int a[N + 10][N + 10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string s[N + 10];
queue<pair<int, int>> dl;
int dis[N + 10][N + 10];

void bfs(int X, int Y)
{
    dl.push({X, Y});
    dis[X][Y] = 1;
    while (!dl.empty())
    {
        int x = dl.front().first, y = dl.front().second;
        dl.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 1 && tx <= r && ty >= 1 && ty <= c)
            {
                if (a[tx][ty] == 0 && dis[tx][ty] == 0)
                {
                    dis[tx][ty] = dis[x][y] + 1;
                    dl.push({tx, ty});
                }
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    int x1, y1;
    int x0, y0;
    for (int i = 1; i <= r; i++)
    {
        cin >> s[i];
        for (int j = 0; j < c; j++)
            if (s[i][j] == 'E')
            {
                x0 = i;
                y0 = j + 1;
            }
            else if (s[i][j] == 'T')
            {
                a[i][j + 1] = 1;
            }
            else if (s[i][j] == 'S')
            {
                x1 = i;
                y1 = j + 1;
            }
    }
    bfs(x0, y0);
    int temp = dis[x1][y1];
    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 0; j < c; j++)
            if (s[i][j] >= '1' && s[i][j] <= '9')
            {
                if (dis[i][j + 1] > 0 && dis[i][j + 1] <= temp)
                {
                    ans += (s[i][j] - '0');
                }
            }
    cout << ans << endl;
    return 0;
}