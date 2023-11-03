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

// h + 2r.pi

void solve(int T)
{
    ll r, h;
    cin >> r >> h;
    double pi = 3.14159265359, vol = 1.0 * 2.0 * r * pi + 1.0 * h;
    ll left = 0, right = 1000000000, mid, ans = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        double v = 0.5 * mid * r * pi;
        if (v <= vol)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
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