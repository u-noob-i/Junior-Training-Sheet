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

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define vii vector<int>
#define ll long long
#define INF 1e9

int sta[200001][25], stb[200001][25];
int a[200001], b[200001], lg[200001];

void build(int n)
{
    rep(i, 0, n)
    {
        sta[i][0] = a[i];
        stb[i][0] = b[i];
    }
    for (int j = 1; j < 25; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            sta[i][j] = max(sta[i][j - 1], sta[i + (1 << (j - 1))][j - 1]);
            stb[i][j] = min(stb[i][j - 1], stb[i + (1 << (j - 1))][j - 1]);
        }
    lg[1] = 0;
    rep(i, 2, n + 1) lg[i] = lg[i / 2] + 1;
    return;
}

int getmax(int l, int r)
{
    int j = lg[r - l + 1];
    return max(sta[l][j], sta[r - (1 << j) + 1][j]);
}

int getmin(int l, int r)
{
    int j = lg[r - l + 1];
    return min(stb[l][j], stb[r - (1 << j) + 1][j]);
}

void solve()
{
    int n;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    build(n);
    ll ans = 0;
    rep(i, 0, n)
    {
        int l = i, r = n - 1, mid, j = -1, k = -1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            int x = getmax(i, mid), y = getmin(i, mid);
            if (x == y)
                j = mid;
            if (x < y)
                l = mid + 1;
            else
                r = mid - 1;
        }
        l = i;
        r = n - 1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            int x = getmax(i, mid), y = getmin(i, mid);
            if (x == y)
                k = mid;
            if (x <= y)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (j != -1)
            ans += (k - j + 1);
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