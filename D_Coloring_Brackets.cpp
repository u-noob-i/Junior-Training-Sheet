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
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

ll dp[701][701][3][3];
int p[701];

void rec(int l, int r)
{
    if (l > r)
        return;
    if (l + 1 == r)
    {
        dp[l][r][0][1] = dp[l][r][1][0] = dp[l][r][0][2] = dp[l][r][2][0] = 1;
        return;
    }
    if (p[l] == r)
    {
        rec(l + 1, r - 1);
        rep(i, 0, 2) rep(j, 0, 2)
        {
            if (j != 1)
                dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % M;
            if (j != 2)
                dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % M;
            if (i != 1)
                dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % M;
            if (i != 2)
                dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % M;
        }
        return;
    }
    rec(l, p[l]);
    rec(p[l] + 1, r);
    rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2) rep(q, 0, 2)
    {
        if (j == k && j)
            continue;
        dp[l][r][i][q] = (dp[l][r][i][q] + (dp[l][p[l]][i][j] * dp[p[l] + 1][r][k][q]) % M) % M;
    }
    return;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    s = "#" + s;
    stack<int> a;
    rep(i, 1, n)
    {
        if (s[i] == ')')
        {
            int j = a.top();
            a.pop();
            p[i] = j;
            p[j] = i;
        }
        else
            a.push(i);
    }
    rec(1, n);
    ll ans = 0;
    rep(i, 0, 2) rep(j, 0, 2) ans = (ans + dp[1][n][i][j]) % M;
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