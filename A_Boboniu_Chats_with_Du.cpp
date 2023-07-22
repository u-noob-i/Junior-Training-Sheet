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
    int n, d, i, j;
    ll m, x;
    cin >> n >> d >> m;
    vector<ll> a, b;
    rep(i, 0, n)
    {
        cin >> x;
        if (x > m)
            b.push_back(x);
        else
            a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    rep(i, 1, a.size()) a[i] += a[i - 1];
    rep(i, 1, b.size()) b[i] += b[i - 1];
    ll ans = 0;
    if (a.size())
        ans = a[a.size() - 1];
    rep(i, 0, b.size())
    {
        j = n - 1 - (1 + d) * (i);
        if (j < 0)
            break;
        j = min(j, (int)a.size());
        if (!j)
            ans = max(ans, b[i]);
        else
            ans = max(ans, b[i] + a[j - 1]);
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