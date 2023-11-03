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

void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<int> dp(n, 0);
    rep(i, 0, m)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        a[i] = {u, v, d};
    }
    sort(a.begin(), a.end(), [&](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
    rep(i, 0, m)
    {
        int j = i;
        while (j < m - 1 && a[j + 1][2] == a[j][2])
            j++;
        map<int, int> arr;
        while (i <= j)
        {
            int u = a[i][0], v = a[i][1];
            arr[v] = max(arr[v], dp[v]);
            arr[v] = max(arr[v], 1 + dp[u]);
            ans = max(ans, arr[v]);
            i++;
        }
        for (auto &itr : arr)
            dp[itr.first] = itr.second;
        i--;
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