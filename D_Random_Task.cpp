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

ll nCr[64][64];

ll getct(ll x, int k)
{
    ll ret = 0;
    int taken = 0;
    irep(i, 62, 0)
    {
        if ((1ll << i) & x)
        {
            if (taken <= k && i >= k - taken)
                ret += nCr[i][k - taken];
            taken++;
        }
    }
    if (taken == k)
        ret++;
    return ret;
}

void solve()
{
    nCr[0][0] = 1;
    rep(i, 1, 63) rep(j, 0, i + 1)
    {
        if (!j)
            nCr[i][j] = 1;
        else
            nCr[i][j] = nCr[i][j - 1] * (i - j + 1) / (j);
    }
    ll m, k;
    cin >> m >> k;
    ll l = 1, r = 1e18, mid, ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        ll count = getct(2 * mid, k) - getct(mid, k);
        if (count == m)
        {
            ans = mid;
            break;
        }
        if (count < m)
            l = mid + 1;
        else
            r = mid - 1;
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