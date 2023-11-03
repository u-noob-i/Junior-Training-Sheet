#include <iostream>
#include <cstring>
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

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

int a[18];
ll dp[1 << 18][101];
ll fact[18];

void cf()
{
    fact[0] = 1;
    rep(i, 1, 17) fact[i] = fact[i - 1] * i;
}

void solve()
{
    cf();
    int n, m;
    ll x;
    cin >> x >> m;
    n = 0;
    vi ct(10, 0);
    rep(i, 0, 17)
    {
        if (!x)
            break;
        a[i] = x % 10;
        ct[a[i]]++;
        x /= 10;
        n++;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    rep(mask, 0, (1 << n) - 1) rep(j, 0, m - 1)
    {
        if (!dp[mask][j])
            continue;
        rep(i, 0, n - 1)
        {
            if (((1 << i) & mask) || (!mask && !a[i]))
                continue;
            dp[mask | (1 << i)][(j * 10 + a[i]) % m] += dp[mask][j];
        }
    }
    ll ans = dp[(1 << n) - 1][0];
    rep(i, 0, 9) ans /= fact[ct[i]];
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
