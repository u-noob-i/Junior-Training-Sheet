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

ll M = 1000000007;

bool check(vector<vector<int>> &adjlist, vector<bool> &visited, set<int> &par, int u)
{
    visited[u] = 1;
    par.insert(u);
    rep(i, 0, adjlist[u].size())
    {
        int v = adjlist[u][i];
        if (par.find(v) != par.end())
            return 1;
        if (visited[v])
            continue;
        if (check(adjlist, visited, par, v))
            return 1;
    }
    par.erase(u);
    return 0;
}

bool hascyc(vector<vector<int>> &adjlist, int n)
{
    vector<bool> visited(n, 0);
    rep(i, 0, n)
    {
        if (visited[i])
            continue;
        set<int> par;
        if (check(adjlist, visited, par, i))
            return 1;
    }
    return 0;
}

void solve(int T)
{
    int n, m, i, j, u, v;
    cin >> n >> m;
    vector<vector<vector<int>>> adjlist(n);
    vector<vector<int>> edges(m), a1(n);
    map<vector<int>, int> e;
    vector<int> degree(n, 0);
    rep(i, 0, m)
    {
        cin >> j >> u >> v;
        u--;
        v--;
        edges[i] = {u, v, i};
        adjlist[v].push_back({u, j});
        if (j)
        {
            a1[u].push_back(v);
            degree[u]++;
        }
        else
        {
            adjlist[u].push_back({v, j});
            e[{min(u, v), max(u, v)}] = i;
        }
    }
    if (hascyc(a1, n))
    {
        cout << "NO";
        return;
    }
    vector<bool> visited(n, 0);
    set<int> s;
    rep(i, 0, n) if (!degree[i]) s.insert(i);
    while (s.size())
    {
        u = *s.begin();
        s.erase(u);
        visited[u] = 1;
        rep(i, 0, adjlist[u].size())
        {
            v = adjlist[u][i][0], j = adjlist[u][i][1];
            if (visited[v])
                continue;
            if (j == 1)
            {
                degree[v]--;
                if (!degree[v])
                    s.insert(v);
                continue;
            }
            int p = min(u, v), q = max(u, v);
            if (e.find({p, q}) == e.end())
                continue;
            edges[e[{p, q}]] = {v, u, 1};
            e.erase({p, q});
        }
    }
    // rep(i, 0, n) cout << degree[i] << " ";
    // cout << "\n";
    if (e.size())
        cout << "NO";
    else
    {
        cout << "YES";
        rep(i, 0, m) cout << "\n"
                          << edges[i][0] + 1 << " " << edges[i][1] + 1;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}