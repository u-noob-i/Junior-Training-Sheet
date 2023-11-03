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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

double dp[300001], p[18][18], ans[18];
int n;

int getcount(int x)
{
    int ret = 0;
    while (x)
    {
        ret += x & 1;
        x /= 2;
    }
    return ret;
}

double countdp(int mask)
{
    if (dp[mask] != -1)
        return dp[mask];
    int count = getcount(mask);
    dp[mask] = 0;
    double prob = (double)1 / (count * (count + 1) / 2);
    rep(i, 0, n) rep(j, 0, n) if (i != j && ((1 << i) & mask) && !((1 << j) & mask)) dp[mask] += prob * p[i][j] * countdp(mask | (1 << j));
    return dp[mask];
}

void solve(int T)
{
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> p[i][j];
    rep(i, 0, 300001) dp[i] = -1;
    dp[(1 << n) - 1] = 1;
    rep(i, 0, n) ans[i] = countdp((1 << i));
    rep(i, 0, n) cout << fixed << setprecision(6) << ans[i] << " ";
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