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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
ll M = 1000000007;

void solve(int T)
{
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> j;
    sort(a.begin(), a.end());
    vector<int> mval(n + 1, 0), rval(n + 1, 0);
    rep(i, 0, n)
    {
        int l = i, r = n - 1, mid, val;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[i] + k >= a[mid])
            {
                val = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        mval[i + 1] = val - i + 1;
    }
    rval[n] = mval[n];
    irep(i, n - 1, 1) rval[i] = max(mval[i], rval[i + 1]);
    int ans = 0;
    rep(i, 1, n + 1)
        ans = max(ans, mval[i] + ((i + mval[i] <= n) ? rval[i + mval[i]] : 0));
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}