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

class DisjSet {
    int *rank, *parent, n;
 
public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

void solve(int T)
{
    int n, i, j, u, v;
    cin >> n;
    vector<vector<int>> cord(n, vector<int>(2));
    rep(i, 0, n) cin >> cord[i][0] >> cord[i][1];
    vector<ll> c(n), k(n);
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) cin >> k[i];
    vector<vector<ll>> edges;
    rep(i, 0, n) edges.push_back({c[i], i, n});
    rep(i, 0, n) rep(j, i + 1, n)
    {
        edges.push_back({(k[i] + k[j]) * (abs(cord[i][0] - cord[j][0]) + abs(cord[i][1] - cord[j][1])), i, j});
    }
    DisjSet dsu(n + 1);
    sort(edges.begin(), edges.end(), [](const vector<ll> &a, const vector<ll> &b) -> bool
         { return a[0] < b[0]; });
    int count = 0;
    ll cost = 0;
    vector<vector<int>> ans;
    vector<int> towers;
    rep(i,0,edges.size())
    {
        if(count == n)
            break;
        u = edges[i][1], v = edges[i][2];
        if(dsu.find(u)==dsu.find(v))
            continue;
        dsu.Union(u, v);
        cost += edges[i][0];
        count++;
        if(v==n)
            towers.push_back(u);
        else
            ans.push_back({u, v});
    }
    cout << cost << "\n"
         << towers.size() << "\n";
    rep(i, 0, towers.size()) cout << towers[i] + 1 << " ";
    cout << "\n";
    cout << ans.size() << "\n";
    rep(i, 0, ans.size()) cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << "\n";
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