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

ll a[18], dp[300001][18], adjlist[18][18];
ll ans = 0;
int n, m;

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

ll countdp(int mask, int last)
{
    if (dp[mask][last] != -1 || !(mask & (1 << last)))
        return dp[mask][last];
    int nmask = mask ^ (1 << last);
    rep(i, 0, n) if (((1 << i) & nmask)) dp[mask][last] = max(dp[mask][last], countdp(nmask, i) + a[last] + adjlist[i][last]);
    if (getcount(mask) == m)
        ans = max(ans, dp[mask][last]);
    return dp[mask][last];
}

void solve(int T)
{
    rep(i, 0, 18) rep(j, 0, 18) adjlist[i][j] = 0;
    int k;
    cin >> n >> m >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, k)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        adjlist[u][v] = c;
    }
    rep(i, 0, 300001) rep(j, 0, 18) dp[i][j] = -1;
    rep(i, 0, n)
    {
        dp[(1 << i)][i] = a[i];
        if (m == 1)
            ans = max(ans, a[i]);
    }
    rep(i, 0, n) countdp((1 << n) - 1, i);
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
        solve(T);
        cout << "\n";
    }
}