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
#define INF 1e18
ll M = 1e9 + 7;

int a[4001];

void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    // cord compression
    map<int, int> m;
    int N = 0;
    rep(i, 1, n)
    {
        if (!m[a[i]])
        {
            N++;
            m[a[i]] = N;
        }
        a[i] = m[a[i]];
    }

    int ans = 1;
    vvi dp(n + 1, vi(8002, 1));
    irep(i, n, 1) rep(j, i + 1, n)
    {
        int d = 4000 + a[j] - a[i], nd = 4000 + a[i] - a[j];
        dp[i][d] = max(dp[i][d], 1 + dp[j][nd]);
        ans = max(ans, dp[i][d]);
    }
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
