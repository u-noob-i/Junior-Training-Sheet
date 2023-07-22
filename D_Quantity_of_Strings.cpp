#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

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

void solve(int T)
{
    long long mul;
    cin >> n >> mul >> k;
    DisjSet dsu(n + 1);
    for (i = 1; i + k - 1 <= n; i++)
        for (int l = i, r = i + k - 1; l < r; l++, r--)
            dsu.Union(l, r);
    set<int> diff;
    for (i = 1; i <= n; i++)
        diff.insert(dsu.find(i));
    long long ans = 1;
    for (i = 0; i < diff.size(); i++)
        ans = (ans * mul) % M;
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}