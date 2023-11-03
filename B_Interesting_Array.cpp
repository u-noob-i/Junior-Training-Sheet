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

void build(vector<int> &segtree, vector<int> &a, int node, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        segtree[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(segtree, a, 2 * node, l, mid);
    build(segtree, a, 2 * node + 1, mid + 1, r);
    segtree[node] = segtree[2 * node] & segtree[2 * node + 1];
    return;
}

int query(vector<int> &segtree, int node, int l, int r, int tl, int tr)
{
    if (tr < l || tl > r)
        return INT_MAX;
    if (tl >= l && tr <= r)
        return segtree[node];
    int mid = (tl + tr) / 2;
    return (query(segtree, 2 * node, l, r, tl, mid) & query(segtree, 2 * node + 1, l, r, mid + 1, tr));
}

void solve(int T)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<vector<int>> queries(m, vector<int>(3));
    vector<vector<int>> pref(n + 2, vector<int>(32, 0));
    rep(i, 0, m) rep(j, 0, 3) cin >> queries[i][j];
    rep(i, 0, m)
    {
        int l = queries[i][0], r = queries[i][1], x = queries[i][2];
        rep(j, 0, 30)
        {
            if ((1 << j) & x)
            {
                pref[l][j]++;
                pref[r + 1][j]--;
            }
        }
    }
    rep(i, 1, n + 1)
    {
        rep(j, 0, 30)
        {
            pref[i][j] += pref[i - 1][j];
            if (pref[i][j] > 0)
                a[i] |= (1 << j);
        }
    }
    vector<int> segtree(4 * n + 1);
    build(segtree, a, 1, 1, n);
    rep(i, 0, m)
    {
        int l = queries[i][0], r = queries[i][1], x = queries[i][2];
        if (query(segtree, 1, l, r, 1, n) != x)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    rep(i, 1, n + 1) cout << a[i] << " ";
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