#include <iostream>
#include <cstring>
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
int M = 1e9 + 7;

void solve()
{
    int red, green;
    cin >> red >> green;
    int l = 1, r = 1e4, mid, h;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (mid * (mid + 1) / 2 <= red + green)
        {
            h = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    int total = red + green, m = min(red, green), x = max(red, green);
    vi dp(m + 1, 0), t;
    dp[0] = 1;
    rep(i, 1, h)
    {
        bool change = 0;
        int lim = i * (i + 1) / 2;
        t.assign(m + 1, 0);
        rep(j, 0, min(lim, m))
        {
            if (j >= i && j - i <= min(lim - i, m))
                t[j] = (t[j] + dp[j - i]) % M;
            if (lim - j <= x && j <= min(lim - i, m))
                t[j] = (t[j] + dp[j]) % M;
            if (t[j])
                change = 1;
        }
        if (!change)
            break;
        swap(dp, t);
    }
    int ans = 0;
    rep(i, 0, m) ans = (ans + dp[i]) % M;
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
