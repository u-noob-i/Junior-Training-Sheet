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
ll M = 1e9 + 7;

ll cost[301][301];
ll dp[301][301];

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    vvl a(m, vl(3));
    rep(i, 0, m - 1) rep(j, 0, 2) cin >> a[i][j];
    rep(i, 0, 300) rep(j, 0, 300) cost[i][j] = dp[i][j] = 1e18;
    rep(i, 0, m - 1) cost[a[i][0]][a[i][1]] = min(cost[a[i][0]][a[i][1]], a[i][2]);
    irep(i, n - 1, 1) rep(j, 1, n - i + 1)
    {
        if (j > 1)
            cost[j][j + i - 1] = min(cost[j][j + i - 1], cost[j - 1][j + i - 1]);
        if (j + i <= n)
            cost[j][j + i - 1] = min(cost[j][j + i - 1], cost[j][j + i]);
    }
    rep(i, 0, n) dp[i][0] = 0;
    rep(i, 1, n) rep(j, 1, i)
    {
        dp[i][j] = dp[i - 1][j];
        rep(k, 1, i)
        {
            dp[i][j] = min(dp[i][j], dp[i - k][j - k] + cost[i - k + 1][i]);
        }
    }
    if (dp[n][p] == 1e18)
        dp[n][p] = -1;
    cout << dp[n][p];
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
