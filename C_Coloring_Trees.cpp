#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    int k;
    cin >> n >> m >> k;
    vector<long long> a(n + 1);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<long long>> cost(n + 1, vector<long long>(m + 1));
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> cost[i][j];
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(m + 1)));
    for (i = 0; i <= n; i++)
        for (j = 0; j <= k; j++)
            for (int p = 0; p <= m; p++)
                dp[i][j][p] = (long long)(1e18);
    if (a[1] == 0)
        for (i = 1; i <= m; i++)
            dp[1][1][i] = cost[1][i];
    else
        dp[1][1][a[1]] = 0;
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= k; j++)
        {
            if (a[i] == 0)
            {
                for (int p = 1; p <= m; p++)
                {
                    dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j][p] + cost[i][p]);
                    for (int q = 1; q <= m; q++)
                        if (p != q)
                            dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j - 1][q] + cost[i][p]);
                }
            }
            else
            {
                dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j][a[i]]);
                for (int p = 1; p <= m; p++)
                    if (a[i] != p)
                        dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j - 1][p]);
            }
        }
    }
    long long ans = (long long)(1e18);
    for (i = 1; i <= m; i++)
        ans = min(ans, dp[n][k][i]);
    if (ans == (long long)(1e18))
        ans = -1;
    cout << ans;
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}