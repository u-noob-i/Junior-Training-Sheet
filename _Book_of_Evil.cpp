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
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

int n, m, k;
vi adjlist[100001];
pi d[1000001];
set<int> a, b;

void upd(pi &x, int y)
{
    if (1 + y > x.first)
    {
        swap(x.first, x.second);
        x.first = 1 + y;
    }
    else
        x.second = max(x.second, 1 + y);
    return;
}

void dfs1(int u, int p = -1)
{
    d[u] = {-INF, -INF};
    if (a.find(u) != a.end())
        d[u].first = 0;
    for (auto v : adjlist[u])
        if (v != p)
        {
            dfs1(v, u);
            upd(d[u], d[v].first);
        }
    return;
}

void dfs2(int u, int p = -1)
{
    pi x;
    if (p != -1)
    {
        x = d[u];
        if (d[u].first == d[p].first - 1)
            upd(d[u], d[p].second);
        else
            upd(d[u], d[p].first);
    }
    if (d[u].first > k)
        b.erase(u);
    for (auto v : adjlist[u])
        if (v != p)
            dfs2(v, u);
    if (p != -1)
        d[u] = x;
}

void solve()
{
    cin >> n >> m >> k;
    rep(i, 1, m)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    rep(i, 1, n) b.insert(i);
    dfs1(1);
    dfs2(1);
    cout << b.size();
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