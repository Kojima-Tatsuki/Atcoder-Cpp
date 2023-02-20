#include <vector>
#include <queue>
#include <map>

using namespace std;

/// <summary>無向グラフ</summary>
class NonVectorGraph
{
private:
    vector<vector<int>> Vertex;
    vector<vector<int>> Side;

public:
    /// <param name="v">頂点数</param>
    /// <param name="n">辺数</param>
    NonVectorGraph(int v, int n)
    {
        Vertex = vector<vector<int>>(v);
        Side = vector<vector<int>>(n);
    }
};

bool num(char c)
{
    return '0' <= c && c <= '9';
}

dlong charToNumber(char c) { return c - '0'; }

bool isTwoGraph(vector<vector<int>> G, int N)
{
    vector<int> color(N, -1); // color[v]：頂点 v の色が黒なら 1, 白なら 0, 未探索なら -1
    bool result = true;
    // 全ての頂点について
    for (int v = 0; v < N; ++v)
    {
        // 頂点 v がすでに訪問済みであれば、スキップ
        if (color[v] != -1)
        {
            continue;
        }
        // そうでなければ、頂点 v を含む連結成分は未探索
        // 頂点 v の色を白で決め打ちしたうえで、幅優先探索を行う
        queue<int> que; // 探索候補の頂点番号を入れるキュー
        color[v] = 0;
        que.push(v);
        // キューに要素が残っている限り
        while (que.size() > 0)
        {
            int qv = que.front();
            que.pop();
            // 頂点 qv に隣接している頂点 nv について、
            for (auto nv : G[qv])
            {
                // nv がすでに探索済みならば、スキップする
                if (color[nv] != -1)
                {
                    // 隣り合う頂点どうしが同じ色なら、答えは No
                    if (color[nv] == color[qv])
                        return result;
                    continue;
                }
                // そうでなければ、頂点 nv の色を color[qv] と逆にしたうえで、nv も探索候補に入れる
                color[nv] = 1 - color[qv];
                que.push(nv);
            }
        }
    }

    return result;
}

#include <string>
// string を分割する
vector<string> split_naive(const string &s, char delim)
{
    vector<string> elems;
    string item;
    for (char ch : s)
    {
        if (ch == delim)
        {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else
        {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}