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

int N, n, m;

vi adj[200005], adjrev[200005];
pl words[200005];
set<int> sccadj[200005];
vector<bool> vis;
map<string, int> mp;
map<int, string> pm;

bool cmp(int a, int b)
{
    if (words[a].first == words[b].first)
        return words[a].second < words[b].second;
    return words[a].first < words[b].first;
}

void mpins(string &s)
{
    int x = 0;
    rep(i, 0, s.length() - 1)
    {
        s[i] = tolower(s[i]);
        if (s[i] == 'r')
            x++;
    }
    if (mp.find(s) == mp.end())
    {
        N++;
        mp[s] = N;
        pm[N] = s;
        words[N] = {x, s.length()};
    }
    return;
}

void dfs1(int u, vi &order)
{
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v])
            dfs1(v, order);
    order.push_back(u);
}

void dfs2(int u, vi &comp)
{
    vis[u] = 1;
    comp.push_back(u);
    for (auto v : adjrev[u])
        if (!vis[v])
            dfs2(v, comp);
    return;
}

void getmin(int u)
{
    vis[u] = 1;
    for (auto v : sccadj[u])
    {
        if (!vis[v])
            getmin(v);
        if (cmp(v, u))
            words[u] = words[v];
    }
    return;
}

void solve()
{
    cin >> n;
    vi essay(n + 1);
    N = 0;
    string s, p;
    rep(i, 1, n)
    {
        cin >> s;
        mpins(s);
        essay[i] = mp[s];
    }
    cin >> m;
    rep(i, 1, m)
    {
        cin >> s >> p;
        mpins(s);
        mpins(p);
        adj[mp[s]].push_back(mp[p]);
        adjrev[mp[p]].push_back(mp[s]);
    }

    // SCC

    m = 0;
    vi order, comp;
    vis.resize(N + 1, 0);
    rep(i, 1, N) if (!vis[i]) dfs1(i, order);
    reverse(order.begin(), order.end());
    vis.assign(N + 1, 0);
    vi root(N + 1), rootnodes;
    for (auto i : order)
    {
        if (!vis[i])
        {
            m++;
            comp.clear();
            dfs2(i, comp);
            int p = comp[0];
            rootnodes.push_back(p);
            for (auto u : comp)
            {
                root[u] = p;
                if (cmp(u, p))
                    words[p] = words[u];
            }
        }
    }
    rep(i, 1, N)
    {
        for (auto v : adj[i])
        {
            int x = root[i], y = root[v];
            if (x != y)
                sccadj[x].insert(y);
        }
    }

    // SCC
    vis.assign(N + 1, 0);
    for (auto u : rootnodes)
        if (!vis[u])
            getmin(u);
    ll ax = 0, ay = 0;
    rep(i, 1, n)
    {
        ax += words[root[essay[i]]].first;
        ay += words[root[essay[i]]].second;
    }
    cout << ax << " " << ay;
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
