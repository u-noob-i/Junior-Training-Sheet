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
#define INF 1e9

ll M = 1000000007;

vector<int> zfunc(vector<int> &a)
{
    int n = a.size(), l = 0, r = 0;
    vector<int> z(n, 0);
    rep(i, 1, n)
    {
        if (r > i)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && a[i + z[i]] == a[z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve()
{
    int n, m;
    vector<int> a;
    cin >> n >> m;
    vector<vector<int>> adjlist(n);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v)
            swap(u, v);
        int d = v - u;
        adjlist[u].push_back(d);
        adjlist[v].push_back(n - d);
    }
    rep(i, 0, n)
    {
        a.push_back(0);
        sort(adjlist[i].begin(), adjlist[i].end());
        rep(j, 0, adjlist[i].size()) a.push_back(adjlist[i][j]);
    }
    m = a.size();
    // rep(i, 0, m) cout << a[i] << " ";
    // cout << "\n";
    rep(i, 0, m) a.push_back(a[i]);
    vector<int> z = zfunc(a);
    string ans = "No";
    rep(i, 1, m) if (z[i] >= m) ans = "Yes";
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