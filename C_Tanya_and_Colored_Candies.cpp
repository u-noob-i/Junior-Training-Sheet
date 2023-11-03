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
int n, k;
int a[51];
int dp[51][51][2001];
string p;

int gs(int u, int prev, int sec)
{
    if (u < 1 || u > n || sec < 0)
        return 0;
    if (dp[u][prev][sec] != -1)
        return dp[u][prev][sec];
    int val = 0;
    if (a[u] > a[prev] && p[u] != p[prev])
        val = a[u] + gs(u, u, sec);
    val = max(val, gs(u - 1, prev, sec - 1));
    val = max(val, gs(u + 1, prev, sec - 1));
    dp[u][prev][sec] = val;
    return val;
}

void solve()
{
    rep(i, 0, 51) rep(j, 0, 51) rep(q, 0, 2001) dp[i][j][q] = -1;
    int s;
    cin >> n >> s >> k;
    a[0] = 0;
    rep(i, 0, n) cin >> a[i + 1];
    cin >> p;
    p = "a" + p;
    int l = 0, r = 2000, mid, ans = INF;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (gs(s, 0, mid) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
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