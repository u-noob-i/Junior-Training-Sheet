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

ll a[200001], subtree[200001], ms[200001];
vector<vector<int>> adjlist;
ll ans;

void dfs(int u, int p = -1)
{
    subtree[u] = a[u];
    ms[u] = LLONG_MIN;
    vector<ll> nps;
    for (auto v : adjlist[u])
        if (v != p)
        {
            dfs(v, u);
            subtree[u] += subtree[v];
            ms[u] = max(ms[u], ms[v]);
            nps.push_back(ms[v]);
        }
    ms[u] = max(ms[u], subtree[u]);
    sort(nps.begin(), nps.end(), greater<ll>());
    if (nps.size() > 1)
        ans = max(ans, nps[0] + nps[1]);
}

void solve(int T)
{
    int n;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    adjlist.resize(n);
    rep(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    ans = LLONG_MIN;
    dfs(0);
    ans == LLONG_MIN ? (cout << "Impossible") : (cout << ans);
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