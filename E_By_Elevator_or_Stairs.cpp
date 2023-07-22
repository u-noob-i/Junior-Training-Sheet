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

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> k;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (i = 2; i <= n; i++)
        cin >> a[i];
    for (i = 2; i <= n; i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][1] = k;
    for (i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
        dp[i][1] = min(dp[i - 1][0] + b[i] + k, dp[i - 1][1] + b[i]);
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}