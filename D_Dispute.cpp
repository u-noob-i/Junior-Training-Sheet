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

vi a, sz;
vvi adj;

void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n);
    adj.resize(n);
    sz.resize(n, 1);
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    vi v(n, 0), ans;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        if (!a[i])
            q.push(i);
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        if (v[u] != a[u])
            continue;
        ans.pb(u);
        v[u]++;
        for (auto x : adj[u])
        {
            v[x]++;
            if (v[x] == a[x])
                q.push(x);
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x + 1 << " ";
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
