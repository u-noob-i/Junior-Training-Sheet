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
#define INF 1e18

ll M = 1000000007;

void solve(int T)
{
    int n, query;
    cin >> n >> query;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];
    while (query--)
    {
        ll p, q, ans = -INF;
        int x = n + 1, y = n + 2;
        cin >> p >> q;
        vector<ll> dp(n + 3, -INF);
        rep(i, 0, n)
        {
            ll val = q * a[i];
            val = max(val, dp[c[i]] + p * a[i]);
            if (x != c[i])
                val = max(val, dp[x] + q * a[i]);
            else
                val = max(val, dp[y] + q * a[i]);
            dp[c[i]] = max(dp[c[i]], val);
            ans = max(ans, dp[c[i]]);
            if (x == c[i] || y == c[i])
            {
                if (dp[x] < dp[y])
                    swap(x, y);
            }
            else if (dp[c[i]] >= dp[x])
            {
                y = x;
                x = c[i];
            }
            else if (dp[c[i]] >= dp[y])
                y = c[i];
        }
        cout << max(0ll, ans) << "\n";
    }
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