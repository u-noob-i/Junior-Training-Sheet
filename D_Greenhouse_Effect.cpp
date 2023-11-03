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

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define ll long long
#define INF 1e9

void solve()
{
    int n, m;
    cin >> n >> m;
    double d;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i] >> d;
    vi dp(n + 1, 1);
    dp[n] = 1;
    irep(i, n - 1, 1) rep(j, i + 1, n) if (a[j] >= a[i]) dp[i] = max(dp[i], 1 + dp[j]);
    int ans = 0;
    rep(i, 1, n) ans = max(ans, dp[i]);
    cout << n - ans;
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