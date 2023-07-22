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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
ll M = 1000000007;

int spf[100001];

void sieve()
{
    rep(i, 1, 100001) spf[i] = i;
    for (i = 2; i < 100001; i += 2)
        spf[i] = 2;
    for (i = 3; i < 100001; i += 2)
        if (spf[i] == i)
            for (j = i + i; j < 100001; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    return;
}

map<ll, ll> factr(ll x)
{
    map<ll, ll> ret;
    while (x > 1)
    {
        ret[spf[x]]++;
        x /= spf[x];
    }
    return ret;
}

ll pow(ll x, ll y)
{
    ll ret = 1;
    while (y--)
        ret *= x;
    return ret;
}

int lcs(string &x, string &y, vector<vector<int>> &dp, int l, int r)
{
    if (l < 0 || r < 0)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = max(0, max(lcs(x, y, dp, l - 1, r), lcs(x, y, dp, l, r - 1)) - 1);
    if (x[l] == y[r])
        dp[l][r] = max(dp[i][j], 2 + lcs(x, y, dp, l - 1, r - 1));
    return dp[l][r];
}

void solve(int T)
{
    string p;
    cin >> n >> m >> s >> p;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    lcs(s, p, dp, n - 1, m - 1);
    int ans = 0;
    rep(i, 0, n) rep(j, 0, m) ans = max(ans, dp[i][j]);
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
        // cout << "\n";
    }
}