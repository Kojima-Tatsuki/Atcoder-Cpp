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

int i, j, k, l;
dlong H, K;

int dfs(vector<vector<char>> &graph, vector<vector<int>> &scores, int ci, int cj, int pi, int pj, int best)
{
    int cScore = scores[pi][pj];
    if (graph[pi][pj] == graph[ci][cj])
        cScore++;
    int cbest = best;

    if (cScore > scores[ci][cj])
    {
        scores[ci][cj] = cScore;
        if (cScore > cbest)
            cbest = cScore;
        int nj = cj + 1;
        int ni = ci + 1;
        if (ci < H && nj < K)
        {

            int sc = dfs(graph, scores, ci, nj, ci, cj, cbest);
            if (sc > cbest)
                cbest = sc;
        }

        if (ni < H && cj < K)
        {
            int sc = dfs(graph, scores, ni, cj, ci, cj, cbest);
            if (sc > cbest)
                cbest = sc;
        }
    }
    return cbest;
}

int main()
{
    cin >> H >> K;

    vector<vector<char>> graph(H, vector<char>(K, 'c'));
    vector<vector<int>> scores(H, vector<int>(K, -1));

    forCount(H, i)
    {
        string s;
        cin >> s;
        forCount(K, k)
        {
            graph[i][k] = s[k];
        }
    }

    int best = dfs(graph, scores, 0, 0, 0, 0, 0);

    cout << best % 998244353 << endl;
}