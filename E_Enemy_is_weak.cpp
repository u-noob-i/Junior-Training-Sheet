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

long long st[4 * 1000001];

void build()
{
    for (i = 0; i <= 4 * 1000000; i++)
        st[i] = 0;
    return;
}

void update(int v, int tl, int tr, int x)
{
    if (tl == tr)
        st[v]++;
    else
    {
        int mid = (tl + tr) / 2;
        if (x <= mid)
            update(2 * v, tl, mid, x);
        else
            update(2 * v + 1, mid + 1, tr, x);
        st[v] = st[2 * v] + st[2 * v + 1];
    }
    return;
}

long long sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return st[v];
    int mid = (tl + tr) / 2;
    return sum(v * 2, tl, mid, l, min(r, mid)) + sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
}

void solve(int T)
{
    cin >> n;
    vector<long long> a(n), b;
    for (i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(b.begin(), b.end());
    map<long long, long long> mp;
    for (i = 0; i < n; i++)
        mp[b[i]] = i + 1;
    for (i = 0; i < n; i++)
        a[i] = mp[a[i]];
    build();
    vector<long long> ans(n);
    long long fin = 0;
    for (i = 0; i < n; i++)
    {
        ans[i] = sum(1, 1, n, a[i] + 1, n);
        update(1, 1, n, a[i]);
    }
    build();
    for (i = n - 1; i >= 0; i--)
    {
        ans[i] *= sum(1, 1, n, 1, a[i] - 1);
        update(1, 1, n, a[i]);
        fin += ans[i];
    }
    cout << fin;
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