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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 998244353;

// 1
// 10
// 2 2 2 1 2 1 2 1 2 15

void solve(int T)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    if (sum % n)
    {
        cout << -1;
        return;
    }
    vector<vector<ll>> ans;
    ll x = sum / n, y;

    priority_queue<pair<int, int>> pq;
    rep(i, 1, n)
    {
        pq.push({(i + 1) * (a[i] / (i + 1)), i});
        if (pq.size() > 3)
            pq.pop();
    }
    while (pq.size())
    {
        ll val = pq.top().first;
        int j = pq.top().second;
        pq.pop();
        ans.push_back({j + 1, 1, val / (j + 1)});
        a[0] += val;
        a[j] -= val;
    }

    vector<pair<int, int>> arr;
    rep(i, 1, n)
    {
        if (!a[i])
            continue;
        ll val = (i + 1) - (a[i] % (i + 1));
        if (val == i + 1)
            val = 0;
        arr.push_back({val, i});
    }
    sort(arr.begin(), arr.end());
    rep(i, 0, arr.size())
    {
        if (arr[i].first > a[0])
            break;
        int j = arr[i].second;
        ans.push_back({1, j + 1, arr[i].first});
        a[j] += arr[i].first;
        a[0] -= arr[i].first;
        ans.push_back({j + 1, 1, a[j] / (j + 1)});
        a[0] += a[j];
        a[j] = 0;
    }
    rep(i, 1, n)
    {
        y = x - a[i];
        if (y < 0)
            continue;
        ans.push_back({1, i + 1, y});
        a[i] += y;
        a[0] -= y;
    }
    rep(i, 0, n)
    {
        if (a[i] != x)
        {
            cout << -1;
            return;
        }
    }
    cout << ans.size();
    rep(i, 0, ans.size()) cout << "\n"
                               << ans[i][0] << " " << ans[i][1] << " " << ans[i][2];
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}