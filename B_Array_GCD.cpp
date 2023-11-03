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
ll dp[1000001][3];

void getprimes(int x, set<int> &primes)
{
    if (x % 2 == 0)
    {
        primes.insert(2);
        while (x % 2 == 0)
            x /= 2;
    }
    for (int i = 3; i <= sqrt(x); i += 2)
        if (x % i == 0)
        {
            primes.insert(i);
            while (x % i == 0)
                x /= i;
        }
    if (x > 2)
        primes.insert(x);
    return;
}

ll calc(vector<int> &a, ll x, ll y, int val)
{
    int n = a.size();
    dp[0][0] = 0;
    dp[0][1] = x;
    dp[0][2] = INF;
    if (a[0] % val)
    {
        if ((a[0] > 1 && (a[0] - 1) % val == 0) || ((a[0] + 1) % val == 0))
            dp[0][0] += y;
        else
            dp[0][0] = INF;
    }
    rep(i, 1, n)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = x + min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
        if (a[i] % val)
        {
            if ((a[i] > 1 && (a[i] - 1) % val == 0) || ((a[i] + 1) % val == 0))
            {
                dp[i][0] += y;
                dp[i][2] += y;
            }
            else
                dp[i][0] = dp[i][2] = INF;
        }
    }
    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

void solve()
{
    ll x, y;
    int n;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = INF;
    set<int> primes;
    getprimes(a[0], primes);
    getprimes(a[0] + 1, primes);
    if (a[0] > 1)
        getprimes(a[0] - 1, primes);
    getprimes(a[n - 1], primes);
    getprimes(a[n - 1] + 1, primes);
    if (a[n - 1] > 1)
        getprimes(a[n - 1] - 1, primes);
    for (auto t : primes)
        ans = min(ans, calc(a, x, y, t));
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