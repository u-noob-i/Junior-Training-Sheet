#include <iostream>
#include <cstring>
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
#define INF 1e9
int M = 1e9 + 7;

class DisjSet
{
public:
    int n, *par, sz;

    DisjSet(int N)
    {
        n = N;
        sz = n;
        par = new int[n];
        rep(i, 0, n - 1)
            par[i] = i;
    }

    DisjSet(const DisjSet &t)
    {
        n = t.n;
        sz = t.sz;
        par = new int[n];
        rep(i, 0, n - 1)
            par[i] = t.par[i];
    }

    int find(int u)
    {
        if (par[u] == u)
            return u;
        par[u] = find(par[u]);
        return par[u];
    }

    void merge(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        sz--;
        par[max(pu, pv)] = min(pu, pv);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi edges(m + 1, vi(2));
    rep(i, 1, m)
    {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }

    vector<DisjSet> pref, suf;
    DisjSet dsu1(n), dsu2(n);
    pref.push_back(dsu1);
    suf.push_back(dsu2);
    rep(i, 1, m)
    {
        dsu1.merge(edges[i][0], edges[i][1]);
        pref.push_back(dsu1);
    }
    irep(i, m, 1)
    {
        dsu2.merge(edges[i][0], edges[i][1]);
        suf.push_back(dsu2);
    }

    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        DisjSet dsu(pref[l - 1]);
        rep(i, 0, n - 1) dsu.merge(i, suf[m - r].find(i));
        cout << dsu.sz << "\n";
    }
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
