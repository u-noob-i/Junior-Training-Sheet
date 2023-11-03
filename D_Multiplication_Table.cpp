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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

ll getcount(ll n, ll m, ll x)
{
    ll count = 0;
    for (ll i = 1; i <= n; i++)
        count += min(m, (x - 1) / i);
    return count;
}

ll ispos(ll x)
{
    for (ll i = 1; i <= sqrt(x); i++)
        if (x % i == 0)
            return 1;
    return 0;
}

void solve(int T)
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = n * m, mid, ans = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        ll count = getcount(n, m, mid);
        if (count < k)
        {
            if (ispos(mid))
                ans = mid;
            l = mid + 1;
        }
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
        solve(T);
        cout << "\n";
    }
}