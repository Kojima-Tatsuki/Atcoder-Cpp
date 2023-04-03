#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define dlong long long
#define forCount(count, i) for (i = 0; i < count; ++i)
#define rforCount(count, i) for (i = count - 1; i >= 0; --i)
// dlong charToNumber(char c) { return c - '0'; }

int i, k, l;
int h, w;
int result = 0;

void happy(vector<vector<int>> masu, vector<int> past, int y, int x)
{
    if (y >= h || x >= w)
        return;

    if (find(past.begin(), past.end(), masu[y][x]) != past.end())
    { // find
        return;
    }

    if (y == h - 1 && x == w - 1)
    {
        result++;
        return;
    }

    // vector<int> cpy;
    // copy(past.begin(), past.end(), cpy.begin());

    past.push_back(masu[y][x]);

    happy(masu, past, y, x + 1);
    happy(masu, past, y + 1, x);

    return;
}

int main()
{
    cin >> h >> w;

    vector<vector<int>> masu(h, vector<int>(w));

    forCount(h, i)
    {
        forCount(w, k)
        {
            cin >> masu[i][k];
        }
    }

    vector<int> iv(0);

    happy(masu, iv, 0, 0);

    cout << result << endl;

    return 0;
}