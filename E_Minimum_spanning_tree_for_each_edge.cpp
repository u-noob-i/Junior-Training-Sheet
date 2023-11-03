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

vector<int> tin, tout;
vector<vector<vector<int>>> adjlist;
vector<vector<int>> up, maxedge;

int l;

class DisjSet {
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
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

bool isancestor(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void dfsup(int u, int p, int e, int &t)
{
    tin[u] = t++;

    up[u][0] = p;
    maxedge[u][0] = e;
    for (int i = 1; i <= l; i++)
    {    
        up[u][i] = up[up[u][i - 1]][i - 1];
        maxedge[u][i] = max(maxedge[u][i - 1], maxedge[up[u][i - 1]][i - 1]);
    }

    for (int i = 0; i < adjlist[u].size(); i++)
    {
        int v = adjlist[u][i][0];
        if (v == p)
            continue;
        dfsup(v, u, adjlist[u][i][1], t);
    }

    tout[u] = t++;
}

int LCA(int u, int v)
{
    if (isancestor(u, v))
        return u;
    if (isancestor(v, u))
        return v;
    for (int i = l; i >= 0; i--)
        if (!isancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int getmaxedge(int u, int p)
{
    int ret = 0;
    for (int i = l; i >= 0; i--)
        if (isancestor(p, up[u][i]))
        {
            ret = max(ret, maxedge[u][i]);
            u = up[u][i];
            if (p == u)
                break;
        }
    return ret;
}

void solve(int T)
{
    int n, m, u, v;
    cin >> n >> m;
    adjlist.resize(n);
    vector<vector<int>> edges(m, vector<int>(4));
    vector<ll> ans(m, 0);
    rep(i, 0, m)
    {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][3] = i;
        edges[i][1]--;
        edges[i][2]--;
    }
    if (n == 1)
        return;
    sort(edges.begin(), edges.end());
    int count = 0;
    ll cost = 0;
    DisjSet dsu(n);
    for (int i = 0; i < m; i++)
    {
        if (count == n - 1)
            break;
        if (dsu.find(edges[i][1]) != dsu.find(edges[i][2]))
        {
            dsu.Union(edges[i][1], edges[i][2]);
            adjlist[edges[i][1]].push_back({edges[i][2], edges[i][0]});
            adjlist[edges[i][2]].push_back({edges[i][1], edges[i][0]});
            ans[edges[i][3]] = -1;
            cost += edges[i][0];
            count++;
        }
    }
    l = ceil(log2(n));
    int t = 0;
    up.resize(n);
    maxedge.resize(n);
    for (int i = 0; i < n; i++)
    {
        up[i].resize(l + 1);
        maxedge[i].resize(l + 1);
    }
    tin.resize(n);
    tout.resize(n);
    dfsup(0, 0, 0, t);
    for (int i = 0; i < m; i++)
    {
        if (ans[edges[i][3]] == -1)
            ans[edges[i][3]] = cost;
        else
        {
            u = edges[i][1], v = edges[i][2];
            ll w = edges[i][0];
            int lca = LCA(u, v);
            ll x = getmaxedge(u, lca), y = getmaxedge(v, lca);
            ans[edges[i][3]] = cost + w - max(x, y);
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
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