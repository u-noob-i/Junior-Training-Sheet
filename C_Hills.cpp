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

int a[5005];
int dp1[5005][5005], dp2[5005][5005];

void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 0, n + 1) rep(j, 0, (n + 1) / 2) dp1[i][j] = dp2[i][j] = INF;
    rep(i, 0, n) dp1[i][0] = 0;
    vi ans(n + 1, INF);
    rep(i, 1, n) rep(j, 1, (min((i + 1) / 2, (n + 1) / 2)))
    {
        if (j == 1)
        {
            dp1[i][j] = 0;
            if (i > 1)
                dp1[i][j] += max(0, a[i - 1] - a[i] + 1);
            if (i < n)
                dp1[i][j] += max(0, a[i + 1] - a[i] + 1);
        }
        else
        {
            if (i - 2 >= 1)
            {
                int c = dp1[i - 2][j - 1];
                c -= max(0, a[i - 1] - a[i - 2] + 1);
                c += max(0, a[i - 1] - min(a[i - 2], a[i]) + 1);
                if (i < n)
                    c += max(0, a[i + 1] - a[i] + 1);
                dp1[i][j] = c;
            }
            if (i - 3 >= 1)
            {
                int c = dp2[i - 3][j - 1] + max(0, a[i - 1] - a[i] + 1);
                if (i < n)
                    c += max(0, a[i + 1] - a[i] + 1);
                dp1[i][j] = min(dp1[i][j], c);
            }
        }
        dp2[i][j] = min(dp1[i][j], dp2[i - 1][j]);
        ans[j] = min(ans[j], dp2[i][j]);
    }
    // rep(j, 1, (n + 1) / 2)
    // {
    //     rep(i, 1, n) cout << dp1[i][j] << " ";
    //     cout << "\n";
    // }
    rep(i, 1, (n + 1) / 2) cout << ans[i] << " ";
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
