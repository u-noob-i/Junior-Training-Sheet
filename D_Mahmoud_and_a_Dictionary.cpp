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

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

class DisjSet
{
public:
    int *rank, *parent, n;
    DisjSet(int n)
    {
        rank = new int[2 * n];
        parent = new int[2 * n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < 2 * n; i++)
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
        else if (xset < yset)
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
        else
        {
            parent[xset] = yset;
            rank[yset] = rank[yset] + 1;
        }
    }
    bool isFriend(int x, int y)
    {
        if (find(x) == find(y))
            return 1;
        return 0;
    }
    bool isEnemy(int x, int y)
    {
        if ((find(x) == find(y + n)) || (find(x + n) == find(y)))
            return 1;
        return 0;
    }
    void friendMerge(int x, int y)
    {
        Union(x, y);
        Union(x + n, y + n);
    }
    void enemyMerge(int x, int y)
    {
        Union(x, y + n);
        Union(x + n, y);
    }
};

void solve(int T)
{
    cin >> n >> m >> q;
    map<string, int> a;
    DisjSet dsu(n);
    for (i = 0; i < n; i++)
    {
        cin >> s;
        a[s] = i;
    }
    for (i = 0; i < m; i++)
    {
        int x;
        cin >> x >> s >> p;
        if (x == 1)
        {
            if (dsu.isEnemy(a[s], a[p]))
                cout << "NO\n";
            else
            {
                dsu.friendMerge(a[s], a[p]);
                cout << "YES\n";
            }
        }
        else
        {
            if (dsu.isFriend(a[s], a[p]))
                cout << "NO\n";
            else
            {
                dsu.enemyMerge(a[s], a[p]);
                cout << "YES\n";
            }
        }
    }
    for (i = 0; i < q; i++)
    {
        cin >> s >> p;
        if (dsu.isFriend(a[s], a[p]))
            cout << 1 << "\n";
        else if (dsu.isEnemy(a[s], a[p]))
            cout << 2 << "\n";
        else
            cout << 3 << "\n";
    }
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