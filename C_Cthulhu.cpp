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

int sz;
vi p, r;

void dsu(int n)
{
    sz = n;
    p.resize(n);
    r.resize(n);
    rep(i, 0, n - 1)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}

bool merge(int u, int v)
{
    int x = find(u), y = find(v);
    if (x == y)
        return 0;
    sz--;
    if (r[x] < r[y])
        p[x] = y;
    else if (r[y] < r[x])
        p[y] = x;
    else
    {
        p[y] = x;
        r[x]++;
    }
    return 1;
}

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    bool f = 0;
    set<pi> edges;
    rep(i, 0, m - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        if (u > v)
            swap(u, v);
        if (edges.find({u, v}) != edges.end())
            f = 1;
        else
            edges.insert({u, v});
    }
    int cyc = 0;
    dsu(n);
    for (auto &itr : edges)
        if (!merge(itr.first, itr.second))
            cyc++;
    if (f || sz != 1 || cyc != 1)
        cout << "NO";
    else
        cout << "FHTAGN!";
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
