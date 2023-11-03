#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
ll M = 1e9 + 7;

ll GCD(ll x, ll y) { return (y == 0 ? x : GCD(y % x, x)); }

int n, m;
vvi adj, nodes, edges;

void dfs(int u, int num, int p = -1)
{
    for (auto v : adj[u])
    {
        if (p == v)
            continue;
        m++;
        if (!num && m > 1)
            edges.pb({1, m});
        else if (num)
            edges.pb({num, m});
        nodes.pb({u, v});
        dfs(v, m, u);
    }
}

void solve()
{
    cin >> n;
    adj.resize(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    m = 0;
    dfs(1, 0);
    cout << m << "\n";
    for (auto x : nodes)
    {
        cout << x.size() << " ";
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
    for (auto x : edges)
        cout << x[0] << " " << x[1] << "\n";
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

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve();
        cout << "\n";
    }
}
