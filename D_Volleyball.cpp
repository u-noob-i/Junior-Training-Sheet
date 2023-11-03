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

int n, m, s, e;
vector<vector<vector<int>>> a;
vector<vector<int>> adjlist;
vector<ll> d, c;

void cons(int u)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> ans(n, LLONG_MAX);
    pq.push({0, u});
    ans[u] = 0;
    while (pq.size())
    {
        ll dist = pq.top().first, v = pq.top().second;
        pq.pop();
        if (ans[v] < dist)
            continue;
        rep(i, 0, a[v].size())
        {
            int x = a[v][i][0], y = a[v][i][1];
            if (ans[x] > dist + y)
            {
                ans[x] = dist + y;
                pq.push({ans[x], x});
            }
        }
    }
    rep(v, 0, n) if (v != u && ans[v] <= d[u]) adjlist[u].push_back(v);
    return;
}

ll dijkstra()
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> ans(n, LLONG_MAX);
    pq.push({0, s});
    ans[s] = 0;
    while (pq.size())
    {
        ll dist = pq.top().first, u = pq.top().second;
        pq.pop();
        if (ans[u] < dist)
            continue;
        for (auto v : adjlist[u])
            if (ans[v] > dist + c[u])
            {
                ans[v] = dist + c[u];
                pq.push({ans[v], v});
            }
    }
    return (ans[e] == LLONG_MAX ? -1 : ans[e]);
}

void solve(int T)
{
    cin >> n >> m >> s >> e;
    s--;
    e--;
    a.resize(n);
    adjlist.resize(n);
    d.resize(n);
    c.resize(n);
    rep(i, 0, m)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        a[u].push_back({v, x});
        a[v].push_back({u, x});
    }
    rep(i, 0, n) cin >> d[i] >> c[i];
    rep(i, 0, n) cons(i);
    // rep(i, 0, n) rep(j, 0, adjlist[i].size()) cout << i + 1 << " -> " << adjlist[i][j] + 1 << "\n";
    cout << dijkstra();
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