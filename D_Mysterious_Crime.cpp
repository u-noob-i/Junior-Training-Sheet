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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    rep(i, 0, m) rep(j, 0, n) cin >> a[i][j];
    vector<int> pos(n);
    rep(i, 0, n) pos[a[0][i] - 1] = i;
    rep(i, 0, m) rep(j, 0, n) a[i][j] = pos[a[i][j] - 1];
    vector<int> cost(n, n + 1);
    rep(i, 0, m)
    {
        rep(j, 0, n)
        {
            int k = j;
            while (j < n - 1 && a[i][j] + 1 == a[i][j + 1])
                j++;
            while (k <= j)
            {
                cost[a[i][k]] = min(j - k + 1, cost[a[i][k]]);
                k++;
            }
        }
    }
    // rep(i, 0, n) cout << cost[i] << " ";
    // cout << "\n";
    ll ans = 0;
    int i = 0;
    while (i < n)
    {
        ans += 1ll * cost[i] * (cost[i] + 1) / 2;
        i += cost[i];
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