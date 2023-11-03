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

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n + 1, 0), e(n + 1, INF);
    vvi queries(m);
    rep(i, 0, m - 1)
    {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        queries[i] = {t, l, r, x};
        if (t == 1)
            rep(j, l, r) a[j] += x;
        else
            rep(j, l, r) e[j] = min(e[j], x - a[j]);
    }
    rep(i, 1, n) if (e[i] == INF) e[i] = 0;
    a = e;
    rep(i, 0, m - 1)
    {
        if (queries[i][0] == 1)
            rep(j, queries[i][1], queries[i][2]) e[j] += queries[i][3];
        else
        {
            int x = -INF;
            rep(j, queries[i][1], queries[i][2]) x = max(x, e[j]);
            if (x != queries[i][3])
            {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES\n";
    rep(i, 1, n) cout << a[i] << " ";
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