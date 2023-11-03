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
    int n;
    cin >> n;
    vector<double> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0)), val(n + 1, vector<double>(n + 1, 1));
    double ans = 0;
    rep(i, 1, n + 1)
    {
        rep(j, 1, i + 1)
        {
            dp[i][j] = dp[i - 1][j];
            val[i][j] = val[i - 1][j];
            double p = val[i - 1][j - 1] * a[i] + (1.0 - a[i]) * dp[i - 1][j - 1];
            if (p > dp[i][j])
            {
                dp[i][j] = p;
                val[i][j] = val[i - 1][j - 1] * (1.0 - a[i]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << fixed << setprecision(10) << ans;
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