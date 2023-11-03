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

int n, l, k;
double p[201];
int a[201];
double dp[201][201][201];

double rec(int i, int w, int t)
{
    if (i == n + 1)
    {
        if (t >= l && t <= w + k)
            return 1;
        else
            return 0;
    }
    if (dp[i][w][t] != -1)
        return dp[i][w][t];
    dp[i][w][t] = (1 - p[i]) * rec(i + 1, w, t) +
                  p[i] * rec(i + 1, min(n, w + a[i]), t + 1);
    // cout << i << " " << w << " " << t << " : " << dp[i][w][t] << "\n";
    return dp[i][w][t];
}

void solve()
{
    cin >> n >> l >> k;
    rep(i, 1, n)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i]++;
    }
    rep(i, 0, n) rep(j, 0, n) rep(t, 0, n) dp[i][j][t] = -1;
    cout << fixed << setprecision(9) << rec(1, 0, 0);
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
