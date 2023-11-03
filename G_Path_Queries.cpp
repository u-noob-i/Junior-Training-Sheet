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

ll M = 1000000000000000003;

class DisjSet {
    int *rank, *parent, *size, n;
 
public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        size = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {    
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }
    int getsize(int x)
    {
        int px = find(x);
        return size[px];
    }
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
        {    
            parent[xset] = yset;
            size[yset] += size[xset];
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
            size[xset] += size[yset];
        }
        else {
            parent[yset] = xset;
            size[xset] += size[yset];
            rank[xset] = rank[xset] + 1;
        }
    }
};

void solve(int T)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n - 1);
    rep(i, 0, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());
    vector<ll> ans(200001, 0);
    DisjSet dsu(n);
    int j = 0;
    rep(i, 1, 200001)
    {
        ans[i] = ans[i - 1];
        while (j < n - 1 && edges[j][0] <= i)
        {
            int u = edges[j][1], v = edges[j][2];
            if (dsu.find(u) != dsu.find(v))
            {
                // cout << u + 1 << "->" << v + 1 << ": " << dsu.getsize(u) << ", " << dsu.getsize(v) << "\n";
                ans[i] += 1ll * dsu.getsize(u) * dsu.getsize(v);
                dsu.Union(u, v);
            }
            j++;
        }
    }
    rep(i, 0, m)
    {
        cin >> j;
        cout << ans[j] << " ";
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
        solve(T);
        cout << "\n";
    }
}