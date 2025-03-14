#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int x = 0;
    cin >> n;
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        if (line == "++X" || line == "X++")
            x++;
        else
            x--;
    }
    cout << x;
}