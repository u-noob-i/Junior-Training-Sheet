#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

void solve(int T)
{
    int n, m;
    ll p;
    cin >> n >> m >> p;
    vector<ll> a(n), keys(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> keys[i];
    sort(a.begin(), a.end());
    sort(keys.begin(), keys.end());
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, LLONG_MAX));
    rep(i, 0, m + 1) dp[0][i] = 0;
    rep(i, 1, n + 1)
    {
        rep(j, i, m + 1)
        {
            dp[i][j] = min(dp[i][j - 1],
                           max(abs(a[i - 1] - keys[j - 1]) + abs(keys[j - 1] - p), dp[i - 1][j - 1]));
        }
    }
    cout << dp[n][m];
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}