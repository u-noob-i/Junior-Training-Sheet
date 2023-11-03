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

ll calc(vector<ll> &a, ll x)
{
    ll cost = 0;
    rep(i, 0, a.size()) cost += max(0ll, x - a[i]);
    return cost;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0, hi, lo;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    hi = (sum + n - 1) / n;
    lo = sum / n;
    sort(a.begin(), a.end());
    ll cost = 0;
    rep(i, 0, n)
    {
        if (i < n - sum % n)
            cost += abs(lo - a[i]);
        else
            cost += abs(hi - a[i]);
    }
    cost /= 2;
    if (cost <= k)
    {
        cout << hi - lo;
        return;
    }
    ll l = 0, r = lo, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        cost = calc(a, mid);
        if (cost <= k)
        {
            lo = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    irep(i, n - 1, 1)
    {
        ll dif = a[i] - a[i - 1];
        if (dif * (n - i) <= k)
            k -= dif * (n - i);
        else
        {
            ll l = k / (n - i);
            hi = a[i] - l;
            break;
        }
    }
    // rep(i, 0, n) cout << a[i] << " ";
    // cout << "\n"
    //      << lo << " " << hi << "\n";
    cout << hi - lo;
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