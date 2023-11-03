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

void solve(int T)
{
    int n;
    cin >> n;
    vector<int> p(n, -1), leaf(n, 1);
    vector<ll> a(n, 0);
    rep(i, 1, n)
    {
        cin >> p[i];
        leaf[--p[i]] = 0;
    }
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    irep(i, n - 1, 0)
    {
        ans = max(ans, (a[i] + leaf[i] - 1) / leaf[i]);
        if (!i)
            break;
        leaf[p[i]] += leaf[i];
        a[p[i]] += a[i];
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