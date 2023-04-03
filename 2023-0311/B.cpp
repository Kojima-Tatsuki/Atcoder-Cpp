#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm> // std::sort, std::unique

using namespace std;

#define dlong long long
#define forCount(count, i) for (i = 0; i < count; ++i)
#define rforCount(count, i) for (i = count - 1; i >= 0; --i)
// dlong charToNumber(char c) { return c - '0'; }

int i;

int main()
{
    int count;

    cin >> count;

    vector<bool> vresult(count);

    forCount(count, i)
    {
        int num;
        cin >> num;

        int index = num - 1;

        if (vresult[i] == false)
            vresult[index] = true;
    }

    bool first = true;

    int rcount = 0;

    forCount(count, i)
    {
        if (!vresult[i])
            rcount++;
    }

    cout << rcount << endl;

    forCount(count, i)
    {
        if (!vresult[i])
        {
            if (first)
            {
                first = false;
            }
            else
            {
                cout << " ";
            }
            cout << i + 1;
        }
    }

    cout << endl;
}