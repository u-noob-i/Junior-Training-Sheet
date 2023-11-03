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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(4)), b(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = a[i][0] - a[i][1];
        a[i][3] = i;
        b[i] = a[i];
    }
    sort(a.begin(), a.end(), [&](const vi & x, const vi & y) { return x[2] < y[2]; });
    vl ans(n, 0);
    ll pref = 0 , suf = 0;
    rep(i, 0, n - 1) suf += a[i][1];
    rep(i, 0, n - 1)
    {
        suf -= a[i][1];
        ans[a[i][3]] = pref + suf + 1ll * a[i][1] * i + 1ll * a[i][0] * (n - i - 1);
        pref += a[i][0];
    }
    rep(i, 0, m - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ll cost = min(b[u][0] + b[v][1], b[u][1] + b[v][0]);
        ans[u] -= cost;
        ans[v] -= cost;
    }
    for (auto x : ans)
        cout << x << " ";
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
