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

vector<vector<int>> st(4 * 1000001, vector<int>(3));

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        st[v][0] = st[v][1] = st[v][2] = 0;
        if (s[tl] == '(')
            st[v][1]++;
        else
            st[v][2]++;
    }
    else
    {
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
        int x = min(st[2 * v][1], st[2 * v + 1][2]);
        st[v][0] = st[2 * v][0] + st[2 * v + 1][0] + 2 * x;
        st[v][1] = st[2 * v][1] + st[2 * v + 1][1] - x;
        st[v][2] = st[2 * v][2] + st[2 * v + 1][2] - x;
    }
    return;
}

vector<int> query(int v, int tl, int tr, int l, int r)
{
    if (tl > tr)
        return {0, 0, 0};
    int mid = (tl + tr) / 2;
    vector<int> ret(3);
    if (tl == l && tr == r)
        ret = st[v];
    else if (l > mid)
        ret = query(2 * v + 1, mid + 1, tr, l, r);
    else if (r <= mid)
        ret = query(2 * v, tl, mid, l, r);
    else
    {
        vector<int> x = query(2 * v, tl, mid, l, mid), y = query(2 * v + 1, mid + 1, tr, mid + 1, r);
        int temp = min(x[1], y[2]);
        ret[0] = x[0] + y[0] + 2 * temp;
        ret[1] = x[1] + y[1] - temp;
        ret[2] = x[2] + y[2] - temp;
    }
    // cout << l << " " << r << ": " << ret[0] << ", " << ret[1] << ", " << ret[2] << "\n";
    return ret;
}

void solve(int T)
{
    cin >> s >> m;
    n = s.length();
    build(1, 0, n - 1);
    // for (i = 1; i <= 4 * n; i++)
    //     cout << st[i][0] << " " << st[i][1] << " " << st[i][2] << "\n";
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, l - 1, r - 1)[0] << "\n";
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