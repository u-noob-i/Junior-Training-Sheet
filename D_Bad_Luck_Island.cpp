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

double dp[102][102][102];

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    rep(l, 1, 3)
    {
        rep(i, 0, y) rep(j, 0, z) dp[0][i][j] = 0;
        rep(i, 1, x) rep(j, 0, y) dp[i][j][0] = 1;
        rep(i, 1, x) rep(j, 1, z) dp[i][0][j] = 0;
        rep(i, 1, x) rep(j, 1, y) rep(k, 1, z)
            dp[i][j][k] = (i * k * dp[i - 1][j][k] + i * j * dp[i][j - 1][k] + j * k * dp[i][j][k - 1]) / (i * j + j * k + i * k);
        cout << fixed << setprecision(10) << dp[x][y][z] << " ";
        swap(x, y);
        swap(y, z);
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
        solve();
        cout << "\n";
    }
}