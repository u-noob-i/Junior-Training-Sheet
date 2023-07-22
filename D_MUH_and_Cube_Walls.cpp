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
    cin >> n >> m;
    vector<int> a(n + m + 1);
    rep(i, m + 1, n + m + 1) cin >> a[i];
    rep(i, 0, m) cin >> a[i];
    vector<int> z(n + m + 1, 0);
    int l = 1, r = 1, ans = 0;
    rep(i, 1, n + m + 1)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        if (!z[i])
            z[i] = 1;
        while (i + z[i] < n + m + 1 && a[i + z[i]] - a[z[i]] == a[i] - a[0])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
        if (z[i] >= m && i > m)
            ans++;
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
        // cout << "\n";
    }
}