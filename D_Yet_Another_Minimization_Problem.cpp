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

void solve(int T)
{
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    if (n == 1)
    {
        cout << 0;
        return;
    }
    int ans = INT_MAX, sum = 0, f = 0;
    rep(i, 0, n)
    {
        sum += a[i] + b[i];
        f += a[i] * a[i] + b[i] * b[i];
    }
    f *= (n - 2);
    bool dp[101][10001];
    rep(i, 0, 101) rep(j, 0, 10001) dp[i][j] = 0;
    dp[0][a[0]] = dp[0][b[0]] = 1;
    rep(i, 1, n)
        rep(j, 1, 10001)
            dp[i][j] = dp[i - 1][max(0, j - a[i])] | dp[i - 1][max(0, j - b[i])];
    rep(i, 1, 10001) if (dp[n - 1][i])
        ans = min(ans, f + i * i + (sum - i) * (sum - i));
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}