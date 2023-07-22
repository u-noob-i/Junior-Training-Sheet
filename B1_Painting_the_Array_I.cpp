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

int n, m, i, j, k;
string s;
ll M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, set<int>> nextocc;
    rep(i, 0, n + 1) nextocc[i].insert(INT_MAX);
    rep(i, 0, n) nextocc[a[i]].insert(i);
    int x = 0, y = 0, ans = 0;
    rep(i, 0, n)
    {
        if (y == a[i])
        {
            ans += (x != a[i]);
            x = a[i];
        }
        else if (x == a[i])
        {
            ans += (y != a[i]);
            y = a[i];
        }
        else if (*nextocc[x].begin() < *nextocc[y].begin())
        {
            ans += (x != a[i]);
            x = a[i];
        }
        else
        {
            ans += (y != a[i]);
            y = a[i];
        }
        nextocc[a[i]].erase(i);
    }
    cout << ans;
}

// 1101011
// 10101
// 11

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}