#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <map>

using namespace std;

#define dlong long long
#define forCount(count, i) for (i = 0; i < count; ++i)
#define rforCount(count, i) for (i = count - 1; i >= 0; --i)
// dlong charToNumber(char c) { return c - '0'; }

int i;

int main()
{
    string S;

    cin >> S;

    for (i = 0; i + 1 < S.size(); i++)
    {
        char s1 = S[i];
        char s2 = S[i + 1];

        S[i] = s2;
        S[i + 1] = s1;

        i++;
    }

    cout << S;
}