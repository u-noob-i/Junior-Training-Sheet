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

vector<int> dfs(vector<vector<int>> &adjlist, vector<vector<ll>> &a, ll cost, int u, int p, ll &ans)
{
    vector<int> ret = {0, 0};
    if (a[u][1] != a[u][2])
        ret[a[u][1]]++;
    cost = min(cost, a[u][0]);
    for (auto &v : adjlist[u])
    {
        if (v == p)
            continue;
        vector<int> temp = dfs(adjlist, a, cost, v, u, ans);
        ret[0] += temp[0];
        ret[1] += temp[1];
    }
    int x = min(ret[0], ret[1]);
    ret[0] -= x;
    ret[1] -= x;
    ans += cost * 2ll * x;
    return ret;
}

void solve(int T)
{
    int n, i, u, v;
    cin >> n;
    vector<vector<int>> adjlist(n);
    vector<vector<ll>> a(n, vector<ll>(3));
    rep(i, 0, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    rep(i, 0, n - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    ll ans = 0;
    vector<int> b = dfs(adjlist, a, LLONG_MAX, 0, -1, ans);
    if (b[0] || b[1])
        cout << -1;
    else
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