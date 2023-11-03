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

vpi adjlist[200001];
int pa[200001], ch[200001];

void dfs1(int u, int p = -1)
{
    ch[u] = 0;
    for (auto v : adjlist[u])
        if (v.first != p)
        {
            dfs1(v.first, u);
            ch[u] += v.second + ch[v.first];
        }
    return;
}

void dfs2(int u, int p = -1)
{
    pa[u] = 0;
    for (auto v : adjlist[u])
        if (v.first == p)
        {
            pa[u] = pa[p] + ch[p] - ch[u] + (v.second ? +1 : -1);
            break;
        }
    for (auto v : adjlist[u])
        if (v.first != p)
            dfs2(v.first, u);
    return;
}

void solve()
{
    int n, u, v;
    cin >> n;
    rep(i, 1, n - 1)
    {
        cin >> u >> v;
        adjlist[u].push_back({v, 0});
        adjlist[v].push_back({u, 1});
    }
    dfs1(1);
    dfs2(1);
    map<int, vi> m;
    rep(i, 1, n)
    {
        // cout << pa[i] << " " << ch[i] << "\n";
        m[pa[i] + ch[i]].push_back({i});
    }
    auto itr = m.begin();
    vi b = itr->second;
    sort(b.begin(), b.end());
    cout << itr->first << "\n";
    rep(i, 0, b.size() - 1) cout << b[i] << " ";
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