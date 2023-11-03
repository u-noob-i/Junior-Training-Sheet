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
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 2e18
ll M = 1e9 + 7;

void solve()
{
    int n, m, x = 0, y = 0;
    cin >> n >> m;
    vi a(n + 1), b(m + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
        x ^= a[i];
    }
    rep(i, 1, m)
    {
        cin >> b[i];
        y ^= b[i];
    }
    if (x != y)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    vvi ans(n + 1, vi(m + 1, 0));
    ans[1][1] = x ^ a[1] ^ b[1];
    rep(i, 2, n) ans[i][1] = a[i];
    rep(j, 2, m) ans[1][j] = b[j];
    rep(i, 1, n)
    {
        rep(j, 1, m) cout << ans[i][j] << " ";
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
        solve();
        cout << "\n";
    }
}
