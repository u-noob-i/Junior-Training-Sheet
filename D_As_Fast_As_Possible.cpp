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

bool ispos(int n, double l, double x, double y, double t)
{
    double tbus = (l - (x * t)) / (y - x);
    if (tbus <= 0)
        return 1;
    double dbus = tbus * (y - x);
    double c = 1.0 * dbus / (x + y);
    if (c * (n - 1) + 1.0 * n * tbus > t)
        return 0;
    return 1;
}

void solve(int T)
{
    int n, k;
    double l, x, y, ans;
    cin >> n >> l >> x >> y >> k;
    n = (n + k - 1) / k;
    double left = 0, right = 1000000000, mid;
    int ct = 0;
    while (left < right && ct < 100)
    {
        ct++;
        mid = (left + right) / 2.0;
        if (ispos(n, l, x, y, mid))
        {
            ans = mid;
            right = mid;
        }
        else
            left = mid;
    }
    cout << fixed << setprecision(12) << ans;
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