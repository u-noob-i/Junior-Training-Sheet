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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e9

ll M = 1000000007;

double dp[1001][1001];

double getprob(ll x, ll y)
{
    ll l = 1, r = 1, num = 0, len = y - x + 1;
    while (l <= y)
    {
        ll lo = max(x, l), hi = min(y, r);
        num += max(0ll, hi - lo + 1);
        if (l == 1e18)
            break;
        l *= 10;
        r *= 10;
        r += 9;
    }
    return (1.0 * num) / len;
}

void solve()
{
    int n, k;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    cin >> k;
    rep(i, 0, n + 1)
    {
        dp[0][i] = 0;
        dp[i][0] = 1;
    }
    vector<double> p(n);
    rep(i, 0, n) p[i] = getprob(a[i].first, a[i].second);
    rep(i, 1, n + 1) rep(j, 1, i + 1) dp[i][j] = dp[i - 1][j] * (1.0 - p[i - 1]) + dp[i - 1][j - 1] * p[i - 1];
    cout << fixed << setprecision(9) << dp[n][(k * n + 99) / 100];
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
        solve();
        cout << "\n";
    }
}