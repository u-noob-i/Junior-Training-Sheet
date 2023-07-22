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

int n, m, i, j, k, l;
string s, p;
long long M = 1000000007;

pair<long long, long long> tmin[4 * 200001];

void build(vector<long long> &a, int v, int tl, int tr)
{
    if (tl == tr)
        tmin[v] = {a[tl], 0};
    else
    {
        int mid = (tl + tr) / 2;
        build(a, v * 2, tl, mid);
        build(a, v * 2 + 1, mid + 1, tr);
        tmin[v] = {min(tmin[v * 2].first, tmin[v * 2 + 1].first), 0};
    }
    return;
}

long long mn(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr)
        return tmin[v].first;
    int mid = (tl + tr) / 2;
    return tmin[v].second + min(mn(v * 2, tl, mid, l, min(r, mid)), mn(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r));
}

void update(int v, int tl, int tr, int l, int r, long long add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        tmin[v].first += add;
        tmin[v].second += add;
    }
    else
    {
        int mid = (tl + tr) / 2;
        update(v * 2, tl, mid, l, min(r, mid), add);
        update(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r, add);
        tmin[v].first = min(tmin[v * 2].first, tmin[v * 2 + 1].first) + tmin[v].second;
    }
    return;
}

void solve(int T)
{
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    cin >> m;
    getline(cin, s);
    while (m--)
    {
        getline(cin, s);
        stringstream X(s);
        long long x[3];
        x[2] = INT_MAX;
        i = 0;
        s = "";
        while (getline(X, s, ' '))
            x[i++] = stoi(s);
        if (x[2] == INT_MAX)
        {
            if (x[0] <= x[1])
                cout << mn(1, 1, n, x[0] + 1, x[1] + 1) << "\n";
            else
                cout << min(mn(1, 1, n, x[0] + 1, n), mn(1, 1, n, 1, x[1] + 1)) << "\n";
        }
        else
        {
            if (x[2] == 0)
                continue;
            if (x[0] <= x[1])
                update(1, 1, n, x[0] + 1, x[1] + 1, x[2]);
            else
            {
                update(1, 1, n, x[0] + 1, n, x[2]);
                update(1, 1, n, 1, x[1] + 1, x[2]);
            }
        }
        // for (i = 1; i <= 4 * n; i++)
        //     cout << "{" << tmin[i].first << ", " << tmin[i].second << "} ";
        // cout << "\n";
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