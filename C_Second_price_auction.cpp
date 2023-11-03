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

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define vii vector<int>
#define ll long long
#define INF 1e9

void solve()
{
    double dp[6][2][3];
    int n, l = INF, r = -INF;
    cin >> n;
    vpi a(n);
    rep(i, 0, n)
    {
        cin >> a[i].first >> a[i].second;
        l = min(l, a[i].first);
        r = max(r, a[i].second);
    }
    double ans = 0;
    rep(p, l, r + 1)
    {
        rep(i, 0, 6) rep(j, 0, 2) rep(k, 0, 3) dp[i][j][k] = 0;
        dp[0][0][0] = 1;
        rep(i, 0, n)
        {
            double pg = 0, pe = 0, pl = 0;
            if (p >= a[i].first && p <= a[i].second)
                pe = 1.0 / (a[i].second - a[i].first + 1);
            pg = 1.0 * min(a[i].second - a[i].first + 1, max(0, a[i].second - p)) / ((a[i].second - a[i].first + 1));
            pl = 1.0 * min(a[i].second - a[i].first + 1, max(0, p - a[i].first)) / (a[i].second - a[i].first + 1);
            rep(k, 0, 3) dp[i + 1][1][k] += pg * dp[i][0][k];
            rep(j, 0, 2) rep(k, 0, 3) dp[i + 1][j][min(2, k + 1)] += pe * dp[i][j][k];
            rep(j, 0, 2) rep(k, 0, 3) dp[i + 1][j][k] += pl * dp[i][j][k];
        }
        ans += (dp[n][0][2] + dp[n][1][1] + dp[n][1][2]) * p;
    }
    cout << fixed << setprecision(9) << ans;
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