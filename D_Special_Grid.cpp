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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i] = "#" + a[i];
    }
    vvi r(n + 1, vi(m + 1, 0)), c(n + 1, vi(m + 1, 0));
    rep(i, 1, n) rep(j, 1, m)
    {
        r[i][j] += r[i][j - 1] + (a[i][j] == '1');
        c[i][j] += c[i - 1][j] + (a[i][j] == '1');
    }
    int d, ans = 0;
    rep(i, 1, n) rep(j, 1, m)
    {
        if (a[i][j] == '1')
            continue;
        d = 1;
        while (i + d >= 1 && i + d <= n && j + d >= 1 && j + d <= m)
        {
            if (a[i + d][j] == '1' || a[i + d][j + d] == '1')
                break;
            if (r[i + d][j + d] == r[i + d][j - 1])
                ans++;
            d++;
        }
        d = 1;
        while (i - d >= 1 && i - d <= n && j + d >= 1 && j + d <= m)
        {
            if (a[i - d][j] == '1' || a[i - d][j + d] == '1')
                break;
            if (r[i - d][j + d] == r[i - d][j - 1])
                ans++;
            d++;
        }
        d = 1;
        while (i + d >= 1 && i + d <= n && j - d >= 1 && j - d <= m)
        {
            if (a[i + d][j] == '1' || a[i + d][j - d] == '1')
                break;
            if (r[i + d][j] == r[i + d][j - d - 1])
                ans++;
            d++;
        }
        d = 1;
        while (i - d >= 1 && i - d <= n && j - d >= 1 && j - d <= m)
        {
            if (a[i - d][j] == '1' || a[i - d][j - d] == '1')
                break;
            if (r[i - d][j] == r[i - d][j - d - 1])
                ans++;
            d++;
        }
        d = 1;
        while (i + d >= 1 && i + d <= n && j - d >= 1 && j + d <= m)
        {
            if (a[i + d][j - d] == '1' || a[i + d][j + d] == '1')
                break;
            if (r[i + d][j + d] == r[i + d][j - d - 1])
                ans++;
            d++;
        }
        d = 1;
        while (i - d >= 1 && i - d <= n && j - d >= 1 && j + d <= m)
        {
            if (a[i - d][j - d] == '1' || a[i - d][j + d] == '1')
                break;
            if (r[i - d][j + d] == r[i - d][j - d - 1])
                ans++;
            d++;
        }
        d = 1;
        while (i - d >= 1 && i + d <= n && j + d >= 1 && j + d <= m)
        {
            if (a[i - d][j + d] == '1' || a[i + d][j + d] == '1')
                break;
            if (c[i + d][j + d] == c[i - d - 1][j + d])
                ans++;
            d++;
        }
        d = 1;
        while (i - d >= 1 && i + d <= n && j - d >= 1 && j - d <= m)
        {
            if (a[i - d][j - d] == '1' || a[i + d][j - d] == '1')
                break;
            if (c[i + d][j - d] == c[i - d - 1][j - d])
                ans++;
            d++;
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
        solve();
        cout << "\n";
    }
}
