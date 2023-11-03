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

void solve(int T)
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    ll ans = 0;
    rep(i, 0, n) rep(j, 0, n)
    {
        cin >> a[i][j];
        ans += a[i][j];
    }
    int k;
    cin >> k;
    while (k--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        a[u][v] = min(a[u][v], c);
        ans = 0;
        rep(i, 0, n) rep(j, 0, n)
        {
            a[i][j] = min(a[i][j], a[i][u] + a[u][v] + a[v][j]);
            a[i][j] = min(a[i][j], a[i][v] + a[u][v] + a[u][j]);
            ans += a[i][j];
        }
        cout << ans / 2 << " ";
    }
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