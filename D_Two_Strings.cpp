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
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    vector<int> a(26, 0), l(n + 1, 0), r(n + 1, 0);
    int x = 0;
    rep(i, 0, n)
    {
        if (x < m && s[i] == p[x])
        {
            x++;
            l[i] = x;
            a[s[i] - 'a'] = x;
        }
        else
            l[i] = a[s[i] - 'a'];
    }
    x = 0;
    irep(i, n - 1, 0)
    {
        if (x < m && s[i] == p[m - 1 - x])
            x++;
        r[i] = x;
    }
    // rep(i, 0, n) cout << l[i] << " ";
    // cout << "\n";
    // rep(i, 0, n) cout << r[i] << " ";
    bool ans = 1;
    rep(i, 0, n) if (!l[i] || l[i] + r[i + 1] < m) ans = 0;
    if (ans)
        cout << "Yes";
    else
        cout << "No";
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