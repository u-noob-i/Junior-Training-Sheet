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
#define INF 1e9

ll M = 1000000007;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<int> b(m);
    rep(i, 0, n)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        rep(j, 0, k) cin >> a[i][j];
    }
    rep(i, 0, m) cin >> b[i];
    vector<vector<ll>> sum(n, vector<ll>(4, -INF));
    ll ans = -INF, s;
    rep(i, 0, n)
    {
        s = 0;
        rep(j, 0, a[i].size())
        {
            s += a[i][j];
            sum[i][2] = max(sum[i][2], s);
        }
        s = 0;
        rep(j, 0, a[i].size()) s += a[i][j];
        sum[i][1] = s;
        s = 0;
        irep(j, a[i].size() - 1, 0)
        {
            s += a[i][j];
            sum[i][0] = max(sum[i][0], s);
        }
        s = 0;
        rep(j, 0, a[i].size())
        {
            s += a[i][j];
            sum[i][3] = max(sum[i][3], s);
            s = max(0ll, s);
        }
    }
    s = 0;
    rep(i, 0, m)
    {
        int j = b[i] - 1;
        ans = max(ans, sum[j][3]);
        ans = max(ans, s + sum[j][2]);
        s = max(s + sum[j][1], sum[j][0]);
        s = max(0ll, s);
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