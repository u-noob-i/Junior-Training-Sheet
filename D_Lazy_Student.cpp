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

class DisjSet
{
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
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

bool comp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] < b[0])
        return 1;
    if (a[0] == b[0] && a[1] > b[1])
        return 1;
    return 0;
}

struct hashFunction
{
    size_t operator()(const pair<int, int> &x) const
    {
        return x.first ^ x.second;
    }
};

void solve(int T)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    vector<pair<int, int>> ans(m);
    rep(i, 0, m)
    {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][2] = i;
    }
    sort(edges.begin(), edges.end(), comp);
    int x = 0, u = 0, v = 2;
    DisjSet dsu(n);
    rep(i, 0, m)
    {
        if (!edges[i][1])
        {
            if (x < v)
            {
                cout << -1;
                return;
            }
            ans[edges[i][2]] = {u + 1, v + 1};
            u++;
            if (u == v - 1)
            {
                u = 0;
                v++;
            }
        }
        else
        {
            dsu.Union(x, x + 1);
            x++;
            ans[edges[i][2]] = {x, x + 1};
            int y = min(m - i - 1, x - 1);
        }
    }
    rep(i, 0, m) cout << ans[i].first << " " << ans[i].second << "\n";
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