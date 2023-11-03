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

class DisjSet
{
private:
    int n;
    int *par, *rank;

public:
    DisjSet(int N)
    {
        n = N;
        par = new int[N];
        rank = new int[N];
        rep(i, 0, n - 1)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u)
    {
        if (par[u] != u)
            par[u] = find(par[u]);
        return par[u];
    }

    void merge(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
            par[pu] = pv;
        else if (rank[pv] < rank[pu])
            par[pv] = pu;
        else
        {
            par[pu] = pv;
            rank[pv]++;
        }
        return;
    }
};

void solve()
{
    int n, m, q, x, y;
    cin >> n >> m >> q;
    DisjSet dsu(n + m);
    while (q--)
    {
        cin >> x >> y;
        dsu.merge(x - 1, n + y - 1);
    }
    set<int> comp;
    rep(i, 0, n + m - 1) comp.insert(dsu.find(i));
    cout << comp.size() - 1;
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
