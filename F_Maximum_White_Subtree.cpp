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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
ll M = 1000000007;

void calc(vector<vector<int>> &adjlist, vector<int> &a, vector<bool> &visited, vector<int> &ans, int cur)
{
    visited[cur] = 1;
    ans[cur] = a[cur];
    for (int x = 0; x < adjlist[cur].size(); x++)
    {
        int v = adjlist[cur][x];
        if (!visited[v])
        {
            calc(adjlist, a, visited, ans, v);
            ans[cur] += max(0, ans[v]);
        }
    }
    return;
}

void dfs(vector<vector<int>> &adjlist, vector<int> &a, vector<bool> &visited, vector<int> &ans, int cur, int par)
{
    visited[cur] = 1;
    ans[cur] += max(0, ans[par] - max(0, ans[cur]));
    for (int x = 0; x < adjlist[cur].size(); x++)
        if (!visited[adjlist[cur][x]])
            dfs(adjlist, a, visited, ans, adjlist[cur][x], cur);
    return;
}

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        if (!a[i])
            a[i]--;
    }
    vector<vector<int>> adjlist(n);
    rep(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> ans(n);
    vector<bool> visited(n, 0);
    calc(adjlist, a, visited, ans, 0);
    rep(i, 1, n) visited[i] = 0;
    rep(i, 0, adjlist[0].size()) dfs(adjlist, a, visited, ans, adjlist[0][i], 0);
    rep(i, 0, n) cout << ans[i] << " ";
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