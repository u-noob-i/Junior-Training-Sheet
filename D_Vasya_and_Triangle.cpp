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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 998244353;

bool check(ll n, ll m, ll b, ll h)
{
    if (b <= n && h <= m)
    {
        cout << "YES\n"
             << "0 0\n"
             << b << " 0\n"
             << "0 " << h;
        return 1;
    }
    return 0;
}

void solve(int T)
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll x = 2ll * n * m;
    if (x % k)
    {
        cout << "NO";
        return;
    }
    x /= k;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i)
            continue;
        if (x % i == 0)
        {
            if (check(n, m, i, x / i))
                return;
            if (check(n, m, x / i, i))
                return;
        }
        ll j = n / i;
        if (x % j == 0)
        {
            if (check(n, m, j, x / j))
                return;
            if (check(n, m, x / j, j))
                return;
        }
    }
    for (ll i = 1; i <= sqrt(m); i++)
    {
        if (m % i)
            continue;
        if (x % i == 0)
        {
            if (check(n, m, i, x / i))
                return;
            if (check(n, m, x / i, i))
                return;
        }
        ll j = m / i;
        if (x % j == 0)
        {
            if (check(n, m, j, x / j))
                return;
            if (check(n, m, x / j, j))
                return;
        }
    }
    cout << "NO";
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