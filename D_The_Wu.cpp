#include <iostream>
#include <cstring>
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
#define INF 1e9
int M = 1e9 + 7;

int a[13];

void solve()
{
    string s, p;
    int n, m, q;
    cin >> n >> m >> q;
    rep(i, 0, n - 1) cin >> a[i];
    map<string, int> ct;
    map<string, vpi> qs;
    vector<pair<string, int>> queries(q);
    vi ans(q);
    rep(i, 1, m)
    {
        cin >> s;
        ct[s]++;
    }
    rep(i, 0, q - 1)
    {
        cin >> queries[i].first >> queries[i].second;
        qs[queries[i].first].push_back({queries[i].second, i});
    }
    for (auto itr : qs)
    {
        s = itr.first;
        vi cost(101, 0);
        for (auto jtr : ct)
        {
            p = jtr.first;
            int t = 0;
            rep(i, 0, n - 1) if (s[i] == p[i]) t += a[i];
            if (t <= 100)
                cost[t] += jtr.second;
        }
        rep(i, 1, 100) cost[i] += cost[i - 1];
        for (auto x : itr.second)
            ans[x.second] = cost[x.first];
    }
    for (auto x : ans)
        cout << x << "\n";
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
