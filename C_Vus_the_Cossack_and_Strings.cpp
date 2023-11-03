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

void solve(int T)
{
    string s, p;
    int n, m;
    cin >> s >> p;
    n = s.length(), m = p.length();
    vector<int> a(n + 1, 0);
    int x = 0;
    rep(i, 0, n)
    {
        a[i + 1] = a[i];
        if (s[i] == '1')
            a[i + 1]++;
    }
    rep(i, 0, m) if (p[i] == '1') x++;

    int ans = 0;
    rep(i, m, n + 1) if ((a[i] - a[i - m]) % 2 == x % 2) ans++;
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
        solve(T);
        cout << "\n";
    }
}