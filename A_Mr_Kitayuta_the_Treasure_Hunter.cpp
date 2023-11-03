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

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e18

ll M = 1000000007;
int dp[30001][501];

int rec(vector<int> &a, int i, int l, int d)
{
    if (i > 30000 || 250 - (d - l) > 500 || 250 - (d - l) < 0)
        return 0;
    if (l <= 1 || a[30000] - a[i - 1] == 0)
        return a[30000] - a[i - 1];
    if (dp[i][250 - (d - l)] != -1)
        return dp[i][250 - (d - l)];
    dp[i][250 - (d - l)] = a[i] - a[i - 1] + max(rec(a, i + l - 1, l - 1, d), max(rec(a, i + l, l, d), rec(a, i + l + 1, l + 1, d)));
    return dp[i][250 - (d - l)];
}

void solve(int T)
{
    rep(i, 0, 30001) rep(j, 0, 501) dp[i][j] = -1;
    int n, l;
    cin >> n >> l;
    vector<int> a(30001, 0);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    rep(i, 1, 30001) a[i] += a[i - 1];
    cout << rec(a, l, l, l);
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