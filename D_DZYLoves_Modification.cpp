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
    int n, m, k;
    ll p, x;
    cin >> n >> m >> k >> p;
    vvl a(n + 1, vl(m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    vl rr(k + 1, 0), cc(k + 1, 0);
    priority_queue<ll> r, c;
    rep(i, 1, n)
    {
        x = 0;
        rep(j, 1, m) x += a[i][j];
        r.push(x);
    }
    rep(j, 1, m)
    {
        x = 0;
        rep(i, 1, n) x += a[i][j];
        c.push(x);
    }
    rep(i, 1, k)
    {
        x = r.top();
        r.pop();
        rr[i] = rr[i - 1] + x;
        x -= p * m;
        r.push(x);
    }
    rep(i, 1, k)
    {
        x = c.top();
        c.pop();
        cc[i] = cc[i - 1] + x;
        x -= p * n;
        c.push(x);
    }
    ll ans = -INF;
    rep(i, 0, k) ans = max(ans, (rr[i] + cc[k - i]) - p * i * (k - i));
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
