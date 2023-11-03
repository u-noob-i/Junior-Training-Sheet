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

int n, d;
vector<int> a;
vector<vector<int>> adjlist;

ll dfs(int u, int root, int p = -1)
{
    ll ret = 1;
    for (auto v : adjlist[u])
        if (v != p && a[v] >= a[root] && a[v] - a[root] <= d)
        {
            if (a[v] == a[root] && v < root)
                continue;
            ret = (ret * (dfs(v, root, u) + 1)) % M;
        }
    return ret;
}

void solve(int T)
{
    cin >> d >> n;
    a.resize(n);
    adjlist.resize(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    ll ans = 0;
    rep(i, 0, n)
    {
        ll x = dfs(i, i);
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
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}