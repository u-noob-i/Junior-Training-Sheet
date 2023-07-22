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
#include <climits>

using namespace std;

int n, m, i, j, k;
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

void dfs(vector<vector<pair<int, int>>> &adjlist, vector<bool> &visited, DisjSet &dsu, int cur)
{
    visited[cur] = 1;
    for (int p = 0; p < adjlist[cur].size(); p++)
    {
        if (!visited[adjlist[cur][p].first] && !adjlist[cur][p].second)
        {
            dsu.Union(cur, adjlist[cur][p].first);
            dfs(adjlist, visited, dsu, adjlist[cur][p].first);
        }
    }
    return;
}

void shortest(vector<vector<int>> &mat)
{
    for (int mid = 0; mid < k; mid++)
        for (i = 0; i < k; i++)
            for (j = 0; j < k; j++)
                if (mat[i][mid] != INT_MAX && mat[mid][j] != INT_MAX && mat[i][j] > mat[i][mid] + mat[mid][j])
                    mat[i][j] = mat[i][mid] + mat[mid][j];
    return;
}

void solve(int T)
{
    cin >> n >> m >> k;
    vector<vector<int>> a(m, vector<int>(3));
    vector<int> c(k), vals(n);
    for (i = 0; i < k; i++)
        cin >> c[i];
    for (i = 0; i < m; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (i = 0, j = 0; i < k; i++)
        while (c[i]--)
            vals[j++] = i;
    vector<vector<pair<int, int>>> adjlist(n);
    for (i = 0; i < m; i++)
    {
        adjlist[a[i][0] - 1].push_back({a[i][1] - 1, a[i][2]});
        adjlist[a[i][1] - 1].push_back({a[i][0] - 1, a[i][2]});
    }
    DisjSet dsu(n);
    vector<bool> visited(n, 0);
    for (i = 0; i < n; i++)
        if (!visited[i])
            dfs(adjlist, visited, dsu, i);
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j < n - 1 && vals[i] == vals[j + 1])
            j++;
        while (i < j)
        {
            if (dsu.find(i) != dsu.find(j))
            {
                cout << "No";
                return;
            }
            i++;
        }
    }
    cout << "Yes\n";
    vector<vector<int>> mat(k, vector<int>(k, INT_MAX));
    for (i = 0; i < k; i++)
        mat[i][i] = 0;
    for (i = 0; i < m; i++)
    {
        int u = vals[a[i][0] - 1], v = vals[a[i][1] - 1], cost = a[i][2];
        mat[u][v] = min(mat[u][v], cost);
        mat[v][u] = min(mat[v][u], cost);
    }
    shortest(mat);
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            cout << (mat[i][j] == INT_MAX ? -1 : mat[i][j]) << " ";
        cout << "\n";
    }
}

int main()
{
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