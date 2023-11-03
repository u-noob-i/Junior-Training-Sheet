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

ll M = 1000000007;

void solve(int T)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, k) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 0, x = 0, y = 0, z = 0;
    rep(i, 0, n) x += a[i];
    rep(i, 0, m) y += b[i];
    rep(i, 0, k) z += c[i];
    vector<ll> temp = {a[0], b[0], c[0]};
    sort(temp.begin(), temp.end());
    ans = x + y + z - 2ll * (temp[0] + temp[1]);
    ans = max(ans, x + y + z - 2ll * min(z, min(x, y)));
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