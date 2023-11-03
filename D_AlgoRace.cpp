#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e9
#define pb push_back()
#define pr pop_back()
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

int n, m, r;
vvvi a, dp;

void fw()
{
    rep(t, 1, m) rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
    {
        if (a[t][i][j] > a[t][i][k] + a[t][k][j])
            a[t][i][j] = a[t][i][k] + a[t][k][j];
    }
    // rep(t, 1, m) rep(i, 1, n)
    // {
    //     rep(j, 1, n) cout << a[t][i][j] << " ";
    //     cout << "\n";
    // }
}

void solve()
{
    cin >> n >> m >> r;
    a.resize(m + 1, vvi(n + 1, vi(n + 1, INF)));
    dp.resize(n + 1, vvi(n + 1, vi(n + 1, INF)));
    rep(i, 1, m) rep(j, 1, n) rep(k, 1, n) cin >> a[i][j][k];
    fw();
    rep(c, 0, n - 1) rep(i, 1, n) rep(j, 1, n)
    {
        if (i == j)
            continue;
        if (!c)
        {
            rep(k, 1, m)
            {
                dp[i][j][c] = min(dp[i][j][c], a[k][i][j]);
            }
        }
        else
        {
            dp[i][j][c] = dp[i][j][c - 1];
            rep(p, 1, n) dp[i][j][c] = min(dp[i][j][c], dp[i][p][c - 1] + dp[p][j][0]);
        }
    }
    rep(i, 1, r)
    {
        int x, y, k;
        cin >> x >> y >> k;
        cout << dp[x][y][min(k, n - 1)] << "\n";
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
