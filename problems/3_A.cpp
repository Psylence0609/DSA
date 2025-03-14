#include <bits/stdc++.h>
using namespace std;

int x, y;

int main()
{
    string start;
    string end;
    cin >> start >> end;
    int start_x = start[0] - 'a' + 1;
    int start_y = start[1];
    int end_x = end[0] - 'a' + 1;
    int end_y = end[1];

    int cost = max(abs(start_x - end_x), abs(start_y - end_y));
    cout << cost << endl;
    int x_diff = start_x - end_x;
    int y_diff = start_y - end_y;
    int diag = 0, lin = 0;

    if (x_diff == 0)
    {
        if (y_diff > 0)
        {
            for (int i = 0; i < y_diff; i++)
            {
                cout << "D" << endl;
            }
        }
        else
        {
            for (int i = 0; i < -y_diff; i++)
            {
                cout << "U" << endl;
            }
        }
        return 0;
    }
    else if (y_diff == 0)
    {
        if (x_diff > 0)
        {
            for (int i = 0; i < x_diff; i++)
            {
                cout << "L" << endl;
            }
        }
        else
        {
            for (int i = 0; i < abs(x_diff); i++)
            {
                cout << "R" << endl;
            }
        }
        return 0;
    }

    if (abs(x_diff) > abs(y_diff))
    {
        diag = abs(y_diff);
        lin = abs(x_diff) - abs(y_diff);
    }
    else
    {
        diag = abs(x_diff);
        lin = abs(y_diff) - abs(x_diff);
    }
    string r;
    if (x_diff > 0 && y_diff > 0)
    {
        for (int i = 0; i < diag; i++)
            cout << "LD" << endl;
        if (abs(x_diff) > abs(y_diff))
            r = "L";
        else
            r = "D";
        for (int i = 0; i < lin; i++)
            cout << r << endl;
    }
    else if (x_diff > 0 && y_diff < 0)
    {
        for (int i = 0; i < diag; i++)
            cout << "LU" << endl;
        if (abs(x_diff) > abs(y_diff))
            r = "L";
        else
            r = "U";
        for (int i = 0; i < lin; i++)
            cout << r << endl;
    }
    else if (x_diff < 0 && y_diff < 0)
    {
        for (int i = 0; i < diag; i++)
            cout << "RU" << endl;
        if (abs(x_diff) > abs(y_diff))
            r = "R";
        else
            r = "U";
        for (int i = 0; i < lin; i++)
            cout << r << endl;
    }
    else
    {
        for (int i = 0; i < diag; i++)
            cout << "RD" << endl;
        if (abs(x_diff) > abs(y_diff))
            r = "R";
        else
            r = "D";
        for (int i = 0; i < lin; i++)
            cout << r << endl;
    }
}