#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>

using namespace std;

int find(int u, vector<int> &parent)
{
    if (u != parent[u])
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void merge(int x, int y, vector<int> &parent, vector<int> &rnk)
{
    x = find(x, parent), y = find(y, parent);

    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;

    if (rnk[x] == rnk[y])
        rnk[y]++;
}

void solve(int T)
{
    cout << "Case #" << T << " : ";
    int n, m;
    cin >> n >> m;
    vector<pair<long long, pair<int, int>>> e(m);
    for (int i = 0; i < m; i++)
    {
        long long z;
        int x, y;
        cin >> x >> y >> z;
        if (y < x)
            swap(x, y);
        e[i].first = z;
        e[i].second.first = x - 1;
        e[i].second.second = y - 1;
    }
    sort(e.begin(), e.end());
    long long cost = 0, taken = 0;
    ;
    vector<int> parent(n), rnk(n, 0), f(m, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        if (find(e[i].second.first, parent) != find(e[i].second.second, parent))
        {
            f[i] = 1;
            taken++;
            cost += e[i].first;
            merge(e[i].second.first, e[i].second.second, parent, rnk);
        }
    }
    for (int i = 1; i < n; i++)
        if (find(i, parent) != find(0, parent))
        {
            cout << "No way";
            return;
        }
    if (taken == m)
        cout << "No second way";
    else
    {
        int x;
        for (int i = 0; i < m; i++)
            if (!f[i])
            {
                x = i;
                break;
            }
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rnk[i] = 0;
        }
        merge(e[x].second.first, e[x].second.second, parent, rnk);
        cost = e[x].first;
        for (int i = 0; i < m; i++)
        {
            if (find(e[i].second.first, parent) != find(e[i].second.second, parent))
            {
                f[m] = 1;
                taken++;
                cost += e[i].first;
                merge(e[i].second.first, e[i].second.second, parent, rnk);
            }
        }
        cout << cost;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
        cout << "\n";
    }
}