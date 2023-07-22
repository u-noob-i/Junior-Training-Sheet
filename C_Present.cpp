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

long long st[4 * 100001];

void build(vector<long long> &a, int v, int tl, int tr)
{
    if (tl == tr)
        st[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        st[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
        st[v] += add;
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int get(int v, int tl, int tr, int pos)
{
    if (tl == tr)
        return st[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return st[v] + get(v * 2, tl, tm, pos);
    else
        return st[v] + get(v * 2 + 1, tm + 1, tr, pos);
}

bool func(vector<long long> &a, long long mini, int w)
{
    long long rem = m;
    build(a, 1, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        int x = get(1, 0, n - 1, i);
        if (mini <= x)
            continue;
        if (rem < mini - x)
            return 0;
        rem -= mini - x;
        update(1, 0, n - 1, i, min(n - 1, i + w - 1), mini - x);
    }
    return 1;
}

void solve(int T)
{
    int w;
    cin >> n >> m >> w;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    long long l = 1, r = 1000000000ll + 100000ll, mid, ans = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (func(a, mid, w))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
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