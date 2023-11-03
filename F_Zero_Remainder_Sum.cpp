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

ll M = 998244353;

void solve(int T)
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    int dp[72][71][71][71];
    rep(i, 0, n + 1) rep(j, 0, m + 1) rep(k, 0, m / 2 + 1) rep(l, 0, d) dp[i][j][k][l] = INT_MIN;
    dp[0][0][0][0] = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            rep(k, 0, m / 2 + 1)
            {
                rep(l, 0, d)
                {
                    if (dp[i][j][k][l] == INT_MIN)
                        continue;
                    int ni = (j == m - 1 ? i + 1 : i);
                    int nj = (j == m - 1 ? 0 : j + 1);
                    if (i != ni)
                        dp[ni][nj][0][l] = max(dp[ni][nj][0][l], dp[i][j][k][l]);
                    else
                        dp[ni][nj][k][l] = max(dp[ni][nj][k][l], dp[i][j][k][l]);
                    if (k + 1 <= m / 2)
                    {
                        int rem = (l + a[i][j]) % d;
                        if (i != ni)
                            dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][k][l] + a[i][j]);
                        else
                            dp[ni][nj][k + 1][rem] = max(dp[ni][nj][k + 1][rem], dp[i][j][k][l] + a[i][j]);
                    }
                }
            }
        }
    }
    cout << max(0, dp[n][0][0][0]);
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