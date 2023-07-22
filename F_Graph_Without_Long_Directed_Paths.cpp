#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

bool dfs(vector<vector<int>> &adjlist, vector<bool> &visited, vector<bool> &degree, int cur, bool in)
{
    visited[cur] = 1;
    degree[cur] = in;
    for (int ind = 0; ind < adjlist[cur].size(); ind++)
    {
        int v = adjlist[cur][ind];
        if (visited[v] && in == degree[v])
            return 0;
        if (visited[v])
            continue;
        if (!dfs(adjlist, visited, degree, v, !in))
            return 0;
    }
    return 1;
}

void solve(int T)
{
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    vector<vector<int>> adjlist(n);
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        edges[i] = {u, v};
    }
    vector<bool> d1(n, 0), d2(n, 0), v1(n, 0), v2(n, 0), fin;
    if (dfs(adjlist, v1, d1, 0, 0))
        fin = d1;
    else if (dfs(adjlist, v2, d2, 0, 1))
        fin = d2;
    else
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (i = 0; i < m; i++)
        if (fin[edges[i].first])
            cout << 1;
        else
            cout << 0;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}