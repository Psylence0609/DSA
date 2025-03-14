#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    const int MAX = 1e5 + 15;
    vector<int> last_mul(MAX, 0);

    for (int i = 1; i <= t; i++)
    {
        int num, y;
        cin >> num >> y;

        int last_index = i - y;
        int total_div = 0, bad_div = 0;

        for (int j = 1; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                total_div += j * j == num ? 1 : 2;

                if (last_mul[j] >= last_index)
                    bad_div++;
                if (j * j != num && last_mul[num / j] >= last_index)
                    bad_div++;

                last_mul[j] = last_mul[num / j] = i;
            }
        }
        int good_div = total_div - bad_div;
        cout << good_div << endl;
    }
}