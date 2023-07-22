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

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int n, m, i, j, k;
string s;
long long M = 1000000007;

int rec(vector<int> &a, vector<vector<int>> &dp, int cur, int time)
{
    if (cur == n)
        return 0;
    if (time > 400)
        return 10000000;
    if (dp[cur][time] != -1)
        return dp[cur][time];
    int val = 10000000, t = abs(a[cur] - time), f = time;
    while (time < 400)
    {
        time++;
        val = min(val, rec(a, dp, cur + 1, time) + t);
    }
    dp[cur][f] = val;
    return dp[cur][f];
}

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n, vector<int>(401, -1));
    int ans = INT_MAX;
    for (i = 1; i <= 400; i++)
        ans = min(ans, rec(a, dp, 0, i));
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}