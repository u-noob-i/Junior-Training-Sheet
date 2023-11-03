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
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 998244353;

void dfs(vector<vector<int>> &adjlist, vector<bool> &visited, set<int> &heads, int u, int s)
{
    visited[u] = 1;
    rep(i, 0, adjlist[u].size())
    {
        int v = adjlist[u][i];
        // cout << u << " -> " << v << "\n";
        if (v == s)
            continue;
        if (visited[v])
        {
            if (heads.find(v) != heads.end())
                heads.erase(v);
            continue;
        }
        dfs(adjlist, visited, heads, v, s);
    }
    return;
}

void dfs1(vector<vector<int>> &adjlist, vector<bool> &visited, stack<int> &s, int u)
{
    visited[u] = 1;
    for (auto v : adjlist[u])
        if (!visited[v])
            dfs1(adjlist, visited, s, v);
    s.push(u);
    return;
}

void dfs2(vector<vector<int>> &adjlist, vector<bool> &visited, int u, vector<int> &comp, int N)
{
    visited[u] = 1;
    comp[u] = N;
    for (auto v : adjlist[u])
        if (!visited[v])
            dfs2(adjlist, visited, v, comp, N);
    return;
}

void solve(int T)
{
    int n, m, s, u, v;
    cin >> n >> m >> s;
    vector<vector<int>> adjlist(n + 1), adj_rev(n + 1), edges(m);
    rep(i, 0, m)
    {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adj_rev[v].push_back(u);
        edges[i] = {u, v};
    }

    vector<bool> visited(n + 1, 0);
    stack<int> arr;
    rep(i, 1, n + 1) if (!visited[i]) dfs1(adjlist, visited, arr, i);
    rep(i, 0, n + 1) visited[i] = 0;
    vector<int> comp(n + 1, -1);
    n = 0;
    while (arr.size())
    {
        int u = arr.top();
        arr.pop();
        if (visited[u])
            continue;
        n++;
        dfs2(adj_rev, visited, u, comp, n);
    }
    s = comp[s];
    adjlist.resize(n + 1);
    visited.resize(n + 1);
    rep(i, 0, n + 1)
    {
        visited[i] = 0;
        adjlist[i].clear();
    }
    rep(i, 0, m) adjlist[comp[edges[i][0]]].push_back(comp[edges[i][1]]);

    set<int> heads;
    heads.insert(s);
    dfs(adjlist, visited, heads, s, s);
    rep(i, 1, n + 1)
    {
        if (!visited[i])
        {
            dfs(adjlist, visited, heads, i, s);
            heads.insert(i);
        }
    }
    cout << heads.size() - 1;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}