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
#define INF 1e9
int M = 1e9 + 7;

int n, m;
ll c;
vi a, b;

bool check(int x)
{
    ll mon = c;
    for (int i = 0, j = n - x; i < x && j < n; i++, j++)
        mon -= max(0, b[i] - a[j]);
    return (mon < 0 ? 0 : 1);
}

void solve()
{
    cin >> n >> m >> c;
    a.resize(n);
    b.resize(m);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, m - 1) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = min(n, m), mid, k;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            k = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    ll s = 0;
    for (int i = 0, j = n - k; i < k && j < n; i++, j++)
    {
        c -= max(0, b[i] - a[j]);
        s += min(b[i], a[j]);
    }
    for (int i = 0, j = n - k; i < k && j < n; i++, j++)
    {
        ll x = min(b[i], a[j]);
        x = min(x, c);
        c -= x;
        s -= x;
    }
    cout << k << " " << s;
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
