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

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void in(vector<long long> &a, int &z)
{
    for (int x = 0; x < z; x++)
        cin >> a[x];
}

int bsl(vector<long long> &a, long long tar)
{
    int l = 0, r = a.size() - 1, mid, ret = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] <= tar)
        {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ret;
}

int bsr(vector<long long> &a, long long tar)
{
    int l = 0, r = a.size() - 1, mid, ret = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] >= tar)
        {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}

long long val(long long x, long long y, long long z)
{
    return ((x - y) * (x - y)) + ((y - z) * (y - z)) + ((z - x) * (z - x));
}

long long check(vector<long long> &a, vector<long long> &b, vector<long long> &c)
{
    int N = a.size(), M = b.size(), K = c.size();
    long long ans = LLONG_MAX;
    for (i = 0; i < N; i++)
    {
        int x = bsl(b, a[i]), y = bsr(c, a[i]);
        if (x != -1 && y != -1)
            ans = min(ans, val(a[i], b[x], c[y]));
        x = bsl(c, a[i]), y = bsr(b, a[i]);
        if (x != -1 && y != -1)
            ans = min(ans, val(a[i], c[x], b[y]));
    }
    return ans;
}

void solve(int T)
{
    cin >> n >> m >> k;
    vector<long long> a(n), b(m), c(k);
    long long ans = LLONG_MAX;
    in(a, n);
    in(b, m);
    in(c, k);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ans = min(ans, check(a, b, c));
    ans = min(ans, check(b, a, c));
    ans = min(ans, check(c, a, b));
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}