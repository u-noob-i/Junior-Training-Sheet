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
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll x = 0, y = 0, ans = 0;
    vector<ll> count(60, 0);
    rep(i, 0, n) rep(j, 0, 60) if (((1ll << j) & a[i]) != 0) count[j]++;
    rep(i, 0, n)
    {
        x = 0;
        y = 0;
        rep(j, 0, 60)
        {
            ll p = (1ll << j) % M, t1 = (p * count[j]) % M, t2 = (p * n) % M;
            if ((a[i] & (1ll << j)) != 0)
            {
                x = (x + t1) % M;
                y = (y + t2) % M;
            }
            else
                y = (y + t1) % M;
        }
        x = (x * y) % M;
        ans = (ans + x) % M;
    }
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