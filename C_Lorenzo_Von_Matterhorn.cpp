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

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 998244353;

long long getLCA(map<pair<long long, long long>, long long> &a, long long u, long long v)
{
    vector<long long> x, y;
    while (u)
    {
        x.push_back(u);
        u /= 2;
    }
    while (v)
    {
        y.push_back(v);
        v /= 2;
    }
    i = x.size() - 1;
    j = y.size() - 1;
    while (i >= 0 && j >= 0 && x[i] == y[j])
    {
        i--;
        j--;
    }
    return x[i + 1];
}

void addTo(map<pair<long long, long long>, long long> &a, long long u, long long v, long long c)
{
    while (v != u)
    {
        a[{v / 2, v}] += c;
        v /= 2;
    }
    return;
}

long long getCost(map<pair<long long, long long>, long long> &a, long long u, long long v)
{
    long long ret = 0;
    while (v != u)
    {
        ret += a[{v / 2, v}];
        v /= 2;
    }
    return ret;
}

void solve(int T)
{
    map<pair<long long, long long>, long long> a;
    cin >> n;
    while (n--)
    {
        long long op, u, v, c;
        cin >> op;
        if (op == 1)
        {
            cin >> u >> v >> c;
            long long lca = getLCA(a, u, v);
            addTo(a, lca, u, c);
            addTo(a, lca, v, c);
        }
        else
        {
            cin >> u >> v;
            long long lca = getLCA(a, u, v);
            cout << getCost(a, lca, u) + getCost(a, lca, v) << "\n";
        }
    }
}

int main()
{
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