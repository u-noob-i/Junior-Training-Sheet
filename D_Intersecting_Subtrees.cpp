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

void solve()
{
    int n, k1, k2, u;
    cin >> n;
    vvi adj(n);
    vi d(n, -1);
    rep(i, 0, n - 2)
    {
        int v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k1;
    vi a(k1);
    rep(i, 0, k1 - 1) cin >> a[i];
    cin >> k2;
    vi b(k2);
    rep(i, 0, k2 - 1) cin >> b[i];
    cout << "B " << b[0] << "\n";
    cout.flush();
    cin >> u;
    if (u == -1)
    {
        cout << "ERROR\n";
        exit(0);
    }
    u--;
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
    int mini = a[0] - 1;
    rep(i, 1, k1 - 1) if (d[mini] > d[a[i] - 1]) mini = a[i] - 1;
    cout << "A " << mini + 1 << "\n";
    cout.flush();
    cin >> u;
    if (u == -1)
    {
        cout << "ERROR\n";
        exit(0);
    }
    int ans = -1;
    rep(i, 0, k2 - 1) if (b[i] == u) ans = mini + 1;
    cout << "C " << ans << "\n";
    cout.flush();
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
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
