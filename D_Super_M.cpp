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
#define vvpi vector<vector<pair<int,int>>>

ll M = 1e9 + 7;

int GCD(int x, int y) { return y == 0 ? x : GCD(y, x % y); }

int n, m;
vi a, sub, d;
vb bad;
vvi adj;

int dfs1(int u, int p = -1)
{
    int ret = 0;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        int x = 1 + dfs1(v, u);
        if (bad[v])
        {
            bad[u] = 1;
            ret += x;
        }
    }
    return ret;
}

void dfs2(int u, int x, int p = -1)
{
    d[u] = x;
    for (auto v : adj[u])
    {
        if (v == p || !bad[v])
            continue;
        dfs2(v, x + 1, u);
    }
}

void solve()
{
    cin >> n >> m;
    a.resize(n + 1);
    bad.assign(n + 1, 0);
    adj.resize(n + 1);
    sub.resize(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int r;
    rep(i, 1, m)
    {
        cin >> r;
        bad[r] = 1;
    }
    int e = dfs1(r);
    d.assign(n + 1, 1e9);
    dfs2(r, 0);
    rep(i, 1, n) if (d[i] != 1e9 && d[i] > d[r]) r = i;
    d.assign(n + 1, 1e9);
    int c = r;
    dfs2(r, 0);
    rep(i, 1, n) if (d[i] != 1e9 && d[i] > d[r]) r = i;
    cout << min(r, c) << "\n" << 2 * e - d[r];
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
    for (int ttt = 1; ttt <= tt; ttt++)
    {
        solve();
        cout << "\n";
    }
}
