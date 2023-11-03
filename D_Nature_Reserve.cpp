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

void solve()
{
    int n;
    cin >> n;
    vpi a(n);
    vi ax(n);
    bool up = 0, down = 0;
    rep(i, 0, n - 1)
    {
        cin >> a[i].first >> a[i].second;
        ax[i] = a[i].first;
        if (a[i].second > 0)
            up = 1;
        else
            down = 1;
        a[i].second = abs(a[i].second);
    }
    if (up && down)
    {
        cout << -1;
        return;
    }
    long double v1, v2, m1, m2, l = -1e15, r = 1e15, ans = INF;
    rep(t, 1, 200)
    {
        m1 = (l * 2 + r) / 3;
        m2 = (l + r * 2) / 3;
        v1 = v2 = 0;
        rep(i, 0, n - 1)
        {
            v1 = max(v1, (powl(m1 - 1.0 * a[i].first, 2) + powl(1.0 * a[i].second, 2)) / (2.0 * a[i].second));
            v2 = max(v2, (powl(m2 - 1.0 * a[i].first, 2) + powl(1.0 * a[i].second, 2)) / (2.0 * a[i].second));
        }
        ans = min(ans, min(v1, v2));
        if (v1 > v2)
            l = m1;
        else
            r = m2;
    }
    cout << fixed << setprecision(9) << ans;
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
