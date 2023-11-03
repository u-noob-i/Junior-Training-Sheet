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

void nxt(vi &a, int k, int d)
{
    irep(i, d, 1)
    {
        if (a[i] < k)
        {
            a[i]++;
            rep(j, i + 1, d)
                a[j] = 1;
            return;
        }
    }
    a[0] = -1;
    return;
}

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vvi a(d + 1, vi(n + 1, 1));
    vi t(d + 1, 1);
    rep(i, 1, n)
    {
        if (t[0] == -1)
        {
            cout << -1;
            return;
        }
        rep(j, 1, d) a[j][i] = t[j];
        nxt(t, k, d);
    }
    rep(i, 1, d)
    {
        rep(j, 1, n) cout << a[i][j] << " ";
        cout << "\n";
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