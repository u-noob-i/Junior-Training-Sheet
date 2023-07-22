#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

class DisjSet
{
    int *rank, *parent, n;

public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

void dfs(vector<vector<pair<int, int>>> &adjlist, vector<vector<int>> &weights, vector<bool> &visited, int beg, int u, int d)
{
    weights[beg][u] = d;
    visited[u] = 1;
    for (int ind = 0; ind < adjlist[u].size(); ind++)
        if (!visited[adjlist[u][ind].first])
            dfs(adjlist, weights, visited, beg, adjlist[u][ind].first, d + adjlist[u][ind].second);
}

void solve(int T)
{
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    DisjSet dsu(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> edges;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[i][j])
                edges.push({a[i][j], {i, j}});
    int count = 0;
    vector<vector<pair<int, int>>> adjlist(n);
    while (edges.size() && count < n - 1)
    {
        pair<int, pair<int, int>> x = edges.top();
        edges.pop();
        int d = x.first, u = x.second.first, v = x.second.second;
        if (dsu.find(u) != dsu.find(v))
        {
            dsu.Union(u, v);
            adjlist[u].push_back({v, d});
            adjlist[v].push_back({u, d});
            count++;
        }
    }
    vector<vector<int>> weights(n, vector<int>(n, -1));
    for (i = 0; i < n; i++)
    {
        vector<bool> visited(n, 0);
        dfs(adjlist, weights, visited, i, i, 0);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != weights[i][j])
            {
                cout << "NO";
                return;
            }
    cout << "YES";
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