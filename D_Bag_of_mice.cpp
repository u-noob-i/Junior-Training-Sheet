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
double dp[1001][1001][2];

void solve()
{
    int w, b;
    cin >> w >> b;
    rep(i, 0, b + 1)
    {
        dp[0][i][0] = 0;
        dp[0][i][1] = 1;
    }
    rep(i, 1, w + 1)
    {
        dp[i][0][0] = dp[i][0][1] = 1;
    }
    rep(i, 1, w + 1) rep(j, 1, b + 1)
    {
        double pw = 1.0 * i / (i + j), pb = 1.0 * j / (i + j);
        dp[i][j][0] = pw + pb * (1 - dp[i][j - 1][1]);
        dp[i][j][1] = pw;
        if (j > 1)
        {
            double pwn = 1.0 * i / (i + j - 1), pbn = 1.0 * (j - 1) / (i + j - 1);
            dp[i][j][1] += pb * (pwn * (1 - dp[i - 1][j - 1][0]) + pbn * (1 - dp[i][j - 2][0]));
        }
        else
            dp[i][j][1] += pb * (1 - dp[i - 1][j - 1][0]);
    }
    cout << fixed << setprecision(9) << dp[w][b][0];
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