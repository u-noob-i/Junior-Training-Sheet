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
#define INF 1e9
ll M = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vi l(n + 1), r(n + 1), p(n + 1, -INF);
    stack<int> s;
    rep(i, 1, n)
    {
        while (s.size() && a[i] < a[s.top()])
        {
            x = s.top();
            s.pop();
            r[x] = i;
        }
        s.push(i);
    }
    while (s.size())
    {
        x = s.top();
        s.pop();
        r[x] = n + 1;
    }
    irep(i, n, 1)
    {
        while (s.size() && a[i] < a[s.top()])
        {
            x = s.top();
            s.pop();
            l[x] = i;
        }
        s.push(i);
    }
    while (s.size())
    {
        x = s.top();
        s.pop();
        l[x] = 0;
    }
    rep(i, 1, n) p[r[i] - l[i] - 1] = max(p[r[i] - l[i] - 1], a[i]);
    irep(i, n - 1, 1) p[i] = max(p[i], p[i + 1]);
    rep(i, 1, n) cout << p[i] << " ";
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
