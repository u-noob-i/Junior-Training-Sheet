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

void solve(int T)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k + 1), c(k + 2, 0);
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, k + 1) cin >> b[i];
    sort(a.begin(), a.end());
    int m = 0;
    rep(i, 0, n) c[a[i]]++;
    irep(i, k, 1)
    {
        c[i] += c[i + 1];
        m = max(m, (c[i] + b[i] - 1) / b[i]);
    }
    vector<vector<int>> ans(m, vector<int>());
    rep(i, 1, n + 1) ans[i % m].push_back(a[i - 1]);
    cout << m;
    rep(i, 0, m)
    {
        cout << "\n"
             << ans[i].size() << " ";
        rep(j, 0, ans[i].size()) cout << ans[i][j] << " ";
    }
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