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

int n, m, i, j, k;
string s;
ll M = 1000000007;

void solve(int T)
{
    ll x, ans = 0;
    cin >> n >> x;
    vector<ll> a(n), left(n + 1), right(n + 2), pref(n + 1, 0);
    rep(i, 0, n)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    left[0] = right[n + 1] = 0;
    rep(i, 1, n + 1) left[i] = max(0ll, left[i - 1] + a[i - 1]);
    irep(i, n, 1) right[i] = max(0ll, right[i + 1] + a[i - 1]);
    set<ll> vals = {0};
    rep(i, 1, n + 1)
    {
        // cout << left[i] << " " << right[i] << "\n";
        // left[i-1] + (pref[r]-pref[l-1]*)x + right[r+1]
        // (left[i-1] - x*pref[l-1]) + (right[r+1] + x*pref[r])
        vals.insert(left[i - 1] - x * pref[i - 1]);
        ans = max(ans, *vals.rbegin() + x * pref[i] + right[i + 1]);
        ans = max(ans, left[i]);
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