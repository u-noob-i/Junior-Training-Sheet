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

int getval(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<vector<int>>> &dp, int x, int y, int k)
{
    if (dp[x][y][k] != -1)
        return dp[x][y][k];
    int val = INT_MAX;
    if (x > 0)
        val = min(val, b[x - 1][y] + getval(a, b, dp, x - 1, y, k - 1));
    if (y > 0)
        val = min(val, a[x][y - 1] + getval(a, b, dp, x, y - 1, k - 1));
    if (x < n - 1)
        val = min(val, b[x][y] + getval(a, b, dp, x + 1, y, k - 1));
    if (y < m - 1)
        val = min(val, a[x][y] + getval(a, b, dp, x, y + 1, k - 1));
    dp[x][y][k] = val;
    return dp[x][y][k];
}

void solve(int T)
{
    int k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m - 1)), b(n - 1, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m - 1) cin >> a[i][j];
    rep(i, 0, n - 1) rep(j, 0, m) cin >> b[i][j];
    if (k % 2)
    {
        rep(i, 0, n)
        {
            rep(j, 0, m) cout << -1 << " ";
            cout << "\n";
        }
        return;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
    rep(i, 0, n) rep(j, 0, m) dp[i][j][0] = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m) cout << 2 * getval(a, b, dp, i, j, k / 2) << " ";
        cout << "\n";
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
        // cout << "\n";
    }
}