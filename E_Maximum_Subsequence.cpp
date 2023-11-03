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

ll M = 998244353;

void rec(vector<int> &a, vector<int> &sums, int i, int n, int m, int cur)
{
    if (i == n)
    {
        sums.push_back(cur);
        return;
    }
    rec(a, sums, i + 1, n, m, cur);
    rec(a, sums, i + 1, n, m, (cur + a[i]) % m);
    return;
}

void solve(int T)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> b, c;
    for (int i = 0; i < n; i += 2)
    {
        b.push_back(a[i] % m);
        if (i < n - 1)
            c.push_back(a[i + 1] % m);
    }
    vector<int> s1, s2;
    rec(b, s1, 0, b.size(), m, 0);
    rec(c, s2, 0, c.size(), m, 0);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int ans = 0;
    rep(i, 0, s1.size()) ans = max(ans, s1[i]);
    rep(i, 0, s2.size()) ans = max(ans, s2[i]);
    rep(i, 0, s1.size())
    {
        int l = 0, r = s2.size() - 1, mid;
        ans = max(ans, (s1[i] + s2[r]) % m);
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (s1[i] + s2[mid] < m)
            {
                ans = max(ans, s1[i] + s2[mid]);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
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
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}