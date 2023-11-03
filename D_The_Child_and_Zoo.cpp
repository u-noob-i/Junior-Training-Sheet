#include <iostream>
#include <cstring>
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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e9
int M = 1e9 + 7;

class DisjSet
{
public:
    int n, *par, *rank, *sz;

    DisjSet(int N)
    {
        n = N;
        par = new int[n];
        rank = new int[n];
        sz = new int[n];
        rep(i, 0, n - 1) par[i] = i, sz[i] = 1, rank[i] = 1;
    }

    int find(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    void merge(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
            par[pu] = pv, sz[pv] += sz[pu];
        else if (rank[pv] < rank[pu])
            par[pv] = pu, sz[pu] += sz[pv];
        else
            par[pv] = pu, rank[pu]++, sz[pu] += sz[pv];
    }
};

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    vpi a(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    vvi adj(n);
    rep(i, 1, m)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(a.begin(), a.end(), [&](const pi &a, const pi &b)
         { return a.first > b.first; });
    ll s = 0;
    set<int> proc;
    DisjSet dsu(n);
    rep(i, 0, n - 1)
    {
        int u = a[i].second;
        for (auto v : adj[u])
        {
            if (proc.find(v) == proc.end())
                continue;
            int x = dsu.find(u), y = dsu.find(v);
            if (x != y)
            {
                s += 1ll * a[i].first * dsu.sz[x] * dsu.sz[y];
                dsu.merge(u, v);
            }
        }
        proc.insert(u);
    }
    double ans = 2.0 * s / (1ll * n * (n - 1));
    cout << fixed << setprecision(9) << ans;
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
        solve();
        cout << "\n";
    }
}
