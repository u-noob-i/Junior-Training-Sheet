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

ll dp[40][40];

void solve()
{
    int n, h;
    cin >> n >> h;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    rep(i, 1, n)
    {
        rep(j, 1, i)
        {
            rep(k, 1, i)
            {
                int l = k - 1, r = i - k;
                ll t = 0;
                rep(p, 0, j - 1) t += dp[l][p];
                dp[i][j] += t * dp[r][j - 1];
                t = 0;
                rep(p, 0, j - 2) t += dp[r][p];
                dp[i][j] += t * dp[l][j - 1];
            }
        }
    }
    ll ans = 0;
    rep(i, h, n) ans += dp[n][i];
    cout << ans;
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
