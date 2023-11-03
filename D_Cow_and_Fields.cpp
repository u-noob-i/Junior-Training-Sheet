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

void dijkstra(vector<vector<int>> &adjlist, vector<int> &dist, int s, int l)
{
    dist[s] = l;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({l, s});
    while (q.size())
    {
        int u = q.top().second, d = q.top().first;
        q.pop();
        if (dist[u] != d)
            continue;
        for (auto v : adjlist[u])
            if (dist[v] > 1 + d)
            {
                dist[v] = 1 + d;
                q.push({1 + d, v});
            }
    }
    return;
}

void solve(int T)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    rep(i, 0, k)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> adjlist(n);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> distsource(n, n + 1), distend(n, n + 1);
    dijkstra(adjlist, distsource, 0, 0);
    dijkstra(adjlist, distend, n - 1, 0);

    vector<pair<int, int>> b(k);
    rep(i, 0, k) b[i] = {distsource[a[i]] - distend[a[i]], a[i]};
    sort(b.begin(), b.end());
    int ma = b[0].second, mb = -1, d = INT_MIN, cur = ma;
    rep(i, 1, k)
    {
        int x = b[i].second;
        if (d < distsource[cur] + distend[x])
        {
            ma = cur;
            mb = x;
            d = distsource[ma] + distend[mb];
        }
        if (distsource[cur] < distsource[x])
            cur = x;
    }

    if (distsource[ma] > distsource[mb])
    {
        distsource[ma] = distsource[mb] + 1;
        dijkstra(adjlist, distsource, ma, distsource[ma]);
    }
    else
    {
        distsource[mb] = distsource[ma] + 1;
        dijkstra(adjlist, distsource, mb, distsource[mb]);
    }
    cout << distsource[n - 1];
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