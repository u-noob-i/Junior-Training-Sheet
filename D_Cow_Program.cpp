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

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define vii vector<int>
#define ll long long
#define INF 1e9

int n;
int a[200001];
ll dp[200001][2];
set<pair<int, bool>> p;

ll calc(int i, bool j)
{
    if (i <= 0 || i > n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (p.find({i, j}) != p.end())
        return -INF;
    p.insert({i, j});
    if (!j)
        dp[i][j] = calc(i + a[i], 1);
    else
        dp[i][j] = calc(i - a[i], 0);
    p.erase({i, j});
    if (dp[i][j] != -INF)
        dp[i][j] += a[i];
    return dp[i][j];
}

void solve()
{
    cin >> n;
    rep(i, 2, n + 1) cin >> a[i];
    rep(i, 1, n + 1) dp[i][0] = dp[i][1] = -1;
    rep(i, 2, n + 1)
    {
        dp[i][0] = calc(i, 0);
        dp[i][1] = calc(i, 1);
    }
    rep(i, 1, n) cout << (calc(1 + i, 1) == -INF ? -1 : i + calc(1 + i, 1)) << "\n";
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