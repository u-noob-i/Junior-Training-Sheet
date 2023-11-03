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

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    int sum = 0;
    rep(i, 1, n + 1) cin >> a[i].first;
    rep(i, 1, n + 1) cin >> a[i].second;
    sort(a.begin(), a.end());
    int ans = INF;
    vector<int> costs(n + 2, 0);
    vector<int> ct(201, 0);
    irep(i, n, 1) costs[i] = costs[i + 1] + a[i].second;
    rep(i, 1, n + 1)
    {
        int j = i;
        while (j < n && a[j + 1].first == a[j].first)
            j++;
        int l = j - i + 1, cur = costs[j + 1], exc = i - 1;
        int k = 0;
        while (exc > l - 1)
        {
            int need = min(exc - l + 1, ct[k]);
            cur += k * need;
            exc -= need;
            k++;
        }
        ans = min(ans, cur);
        while (i <= j)
        {
            ct[a[i].second]++;
            i++;
        }
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