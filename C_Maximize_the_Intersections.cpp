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

bool check(int x, int y, int z, int w)
{
    if ((x > z && x < w && !(y > z && y < w)) || (y > z && y < w && !(x > z && x < w)) ||
        (z > x && z < y && !(w > x && w < y)) || (w > x && w < y && !(z > x && z < y)))
        return 1;
    return 0;
}

void solve(int T)
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k);
    vector<bool> vis(2 * n + 1, 0);
    rep(i, 0, k)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        a[i] = {u, v};
        vis[u] = vis[v] = 1;
    }
    vector<int> have;
    rep(i, 1, 2 * n + 1) if (!vis[i]) have.push_back(i);
    rep(i, 0, n - k) a.push_back({have[i], have[i + n - k]});
    int ans = 0;
    rep(i, 0, n) rep(j, i + 1, n) if (check(a[i][0], a[i][1], a[j][0], a[j][1])) ans++;
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