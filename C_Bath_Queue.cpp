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

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(m + 1);
    rep(i, 1, m) cin >> a[i];
    double dp[55][55][55], C[55][55];
    rep(i, 0, 50) C[i][0] = 1;
    rep(i, 1, 50) rep(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    dp[0][0][0] = 1;
    rep(i, 1, m) rep(j, 0, n) rep(k, 0, n) rep(t, 0, n - j) dp[i][j + t][max(k, (t + a[i] - 1) / a[i])] += dp[i - 1][j][k] * C[n - j][t];
    double ans = 0;
    rep(i, 0, n) ans += dp[m][n][i] * i;
    rep(i, 1, n) ans /= m;
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
