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

int dfs(vector<vector<int>> &adjlist, vector<ll> &subtree, vector<ll> &dp, int u, int p)
{
    subtree[u] = 1;
    dp[u] = 0;
    rep(i, 0, adjlist[u].size())
    {
        if (adjlist[u][i] != p)
        {
            subtree[u] += dfs(adjlist, subtree, dp, adjlist[u][i], u);
            dp[u] += dp[adjlist[u][i]];
        }
    }
    dp[u] += subtree[u];
    return subtree[u];
}

void calc(vector<vector<int>> &adjlist, vector<ll> &subtree, vector<ll> &dp, int u, int p, ll &ans)
{
    int n = adjlist.size();
    dp[p] -= subtree[p] + dp[u];
    subtree[p] -= subtree[u];
    dp[p] += subtree[p];
    dp[u] -= subtree[u];
    subtree[u] = n;
    dp[u] += subtree[u] + dp[p];
    ans = max(ans, dp[u]);
    rep(i, 0, adjlist[u].size()) if (adjlist[u][i] != p) calc(adjlist, subtree, dp, adjlist[u][i], u, ans);
    dp[u] -= subtree[u] + dp[p];
    subtree[u] -= subtree[p];
    dp[u] += subtree[u];
    dp[p] -= subtree[p];
    subtree[p] = n;
    dp[p] += subtree[p] + dp[u];
    return;
}

void solve(int T)
{
    int n, u, v, i;
    cin >> n;
    vector<vector<int>> adjlist(n);
    rep(i, 0, n - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<ll> dp(n, 0), subtree(n, 0);
    dfs(adjlist, subtree, dp, 0, -1);
    ll ans = dp[0];
    rep(i, 0, adjlist[0].size())
        calc(adjlist, subtree, dp, adjlist[0][i], 0, ans);
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