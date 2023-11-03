#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF 1e9
#define pb push_back
#define pr pop_back
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
ll M = 1e9 + 7;

vi tin, tout, sz;
vvi adj;
int t;

void dfs(int u, int p = -1)
{
    tin[u] = ++t;
    sz[u] = 1;
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u), sz[u] += sz[v];
    tout[u] = ++t;
}

void solve()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    adj.resize(n);
    vi toy(m, -1);
    vi degree(n, 0);
    rep(i, 1, k)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (toy[v] == -1)
            toy[v] = u;
        else
        {
            adj[toy[v]].pb(u);
            degree[u]++;
            toy[v] = u;
        }
    }
    t = 0;
    tin.assign(n, -1);
    tout.assign(n, -1);
    sz.resize(n);
    rep(i, 0, n - 1) if (!degree[i]) dfs(i);
    rep(i, 1, q)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        v = toy[v];
        if (v == -1)
            cout << 0 << "\n";
        else if (tin[v] >= tin[u] && tout[v] <= tout[u])
            cout << sz[u] << "\n";
        else
            cout << 0 << "\n";
    }
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
