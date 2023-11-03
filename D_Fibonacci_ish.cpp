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
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 2e18
ll M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vl a(n + 1);
    unordered_map<int, int> ct;
    rep(i, 1, n)
    {
        cin >> a[i];
        ct[a[i]]++;
    }
    int ans = max(2, ct[0]);
    rep(i, 1, n) rep(j, 1, n)
    {
        if (i == j || (!a[i] && !a[j]))
            continue;
        vi u;
        u.push_back(a[i]);
        u.push_back(a[j]);
        ct[a[i]]--;
        ct[a[j]]--;
        int l = 2;
        ll x = a[i], y = a[j];
        while (ct[x + y])
        {
            l++;
            u.push_back(x + y);
            ct[x + y]--;
            swap(x, y);
            y += x;
        }
        ans = max(ans, l);
        rep(i, 0, u.size() - 1) ct[u[i]]++;
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
