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
    ll l, r;
    cin >> l >> r;
    ll x = 0, y = 0;
    irep(i, 62, 0)
    {
        ll t = 1ll << i;
        bool a = 0, b = 0;
        if ((x | t) > r && (y | t) > r)
            continue;
        if ((x | (t - 1)) < l)
        {
            a = 1;
            x = x | t;
        }
        if ((y | (t - 1)) < l)
        {
            b = 1;
            y = y | t;
        }
        if (a || b)
            continue;
        x = x | t;
    }
    cout << (x ^ y);
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