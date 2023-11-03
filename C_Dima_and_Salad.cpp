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

ll GCD(ll x, ll y) { return (y == 0 ? x : GCD(y % x, x)); }

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    vi b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    map<int, int> dp;
    dp[0] = 0;
    rep(i, 1, n)
    {
        map<int, int> t = dp;
        for (auto &itr : dp)
        {
            t[itr.first + a[i] - b[i]*k] =
                max(t[itr.first + a[i] - b[i] * k], itr.second + a[i]);
        }
        swap(t, dp);
    }
    if (!dp[0])
        dp[0] = -1;
    cout << dp[0];
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
