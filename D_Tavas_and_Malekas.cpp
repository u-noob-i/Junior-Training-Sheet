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

vector<int> zfunc(string &s)
{
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    rep(i, 1, n)
    {
        if (r > i)
            z[i] = max(r - i, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    string s(n, '.'), p;
    cin >> p;
    rep(i, 0, m) cin >> a[i];
    irep(i, m - 1, 0)
    {
        a[i]--;
        rep(j, 0, p.length())
        {
            if (s[j + a[i]] != '.')
                break;
            s[j + a[i]] = p[j];
        }
    }
    ll ans = 1;
    string t = p + "#" + s;
    vector<int> z = zfunc(t);
    int j = 0;
    rep(i, 0, n)
    {
        if (j < m && i == a[j])
        {
            if (z[i + p.length() + 1] < p.length())
            {
                ans = 0;
                break;
            }
            j++;
        }
        if (s[i] == '.')
            ans = (ans * 26) % M;
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