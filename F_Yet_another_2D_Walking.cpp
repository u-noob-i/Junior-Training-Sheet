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

long long getd(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve()
{
    int n, m;
    cin >> n;
    map<ll, vector<pair<ll, ll>>> level;
    level[0].push_back({0, 0});
    rep(i, 0, n)
    {
        ll x, y;
        cin >> x >> y;
        level[max(x, y)].push_back({x, y});
    }
    m = level.size();
    for (auto &itr : level)
    {
        sort(itr.second.begin(), itr.second.end(), [&](pair<ll, ll> a, pair<ll, ll> &b)
             {
			if (a.first == b.first)
				return a.second > b.second;
			return a.first < b.first; });
    }
    vector<vector<ll>> dp(m, vector<ll>(2, INF));
    dp[0][0] = dp[0][1] = 0;
    auto itr = level.begin();
    itr++;
    int i = 1;
    ll prev = 0;
    for (auto &itr : level)
    {
        ll lvl = itr.first;
        if (lvl == 0)
            continue;
        pair<ll, ll> curl = itr.second[0], curr = itr.second.back();
        pair<ll, ll> prevl = level[prev][0], prevr = level[prev].back();
        dp[i][0] = min(dp[i - 1][0] + getd(prevl, curr) + getd(curl, curr),
                       dp[i - 1][1] + getd(prevr, curr) + getd(curl, curr));
        dp[i][1] = min(dp[i - 1][0] + getd(prevl, curl) + getd(curl, curr),
                       dp[i - 1][1] + getd(prevr, curl) + getd(curl, curr));
        prev = itr.first;
        i++;
    }
    cout << min(dp[m - 1][0], dp[m - 1][1]);
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