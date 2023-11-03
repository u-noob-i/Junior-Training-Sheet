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
ll M = 1e9 + 7;

void solve()
{
    int k;
    cin >> k;
    if (k % 2 == 0)
    {
        cout << "NO";
        return;
    }
    if (k == 1)
    {
        cout << "YES\n2 1\n2 1";
        return;
    }
    set<pi> a;
    cout << "YES\n";
    // comp 1
    rep(i, 1, k - 1) rep(j, i + 1, k - 1) a.insert({i, j});
    for (int i = 1; i <= k - 1; i += 2)
        a.erase({i, i + 1});
    a.insert({k, k + 1});
    rep(i, 1, k - 1) a.insert({i, k}), a.insert({i, k + 1});
    // comp 2
    rep(i, k + 2, 2 * k) rep(j, i + 1, 2 * k + 2) a.insert({i, j});
    for (int i = k + 2; i <= 2 * k; i += 2)
        a.erase({i, i + 1});
    a.insert({2 * k + 1, 2 * k + 2});
    rep(i, k + 2, 2 * k) a.insert({i, 2 * k + 1}), a.insert({i, 2 * k + 2});
    // bridge
    a.insert({2 * k + 3, 2 * k + 4});
    rep(i, 1, k - 1) a.insert({i, 2 * k + 3});
    rep(i, k + 2, 2 * k) a.insert({i, 2 * k + 4});
    cout << 2 * k + 4 << "\n"
         << a.size() << "\n";
    for (auto &itr : a)
        cout << itr.first << " " << itr.second << "\n";
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
