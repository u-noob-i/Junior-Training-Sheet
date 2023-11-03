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
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 2e18
ll M = 1e9 + 7;

int n, m;
int a[100001];
vvi adj;
vi degree;
vector<bool> vis;
set<int> g;

bool dfs(int u, int x)
{
    vis[u] = 1;
    if (a[u] != x)
        return 0;
    bool ret = 1;
    for (auto v : adj[u])
        if (!vis[v])
            ret &= dfs(v, x);
    return ret;
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    degree.resize(n + 1, 0);
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
    }
    rep(i, 1, n)
    {
        cin >> a[i];
        g.insert(a[i]);
    }
    vi order;
    queue<int> q;
    rep(i, 1, n) if (!degree[i]) q.push(i);
    while (q.size())
    {
        int u = q.front();
        if (g.find(u) != g.end())
            order.push_back(u);
        q.pop();
        for (auto v : adj[u])
        {
            degree[v]--;
            if (!degree[v])
                q.push(v);
        }
    }
    reverse(order.begin(), order.end());
    vis.resize(n + 1, 0);
    rep(i, 0, order.size() - 1)
    {
        if (!dfs(order[i], order[i]))
        {
            cout << -1;
            return;
        }
    }
    cout << order.size() << "\n";
    rep(i, 0, order.size() - 1) cout << order[i] << "\n";
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
        solve();
        cout << "\n";
    }
}
