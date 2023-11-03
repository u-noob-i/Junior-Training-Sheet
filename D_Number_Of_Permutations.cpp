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
ll fact[300001];

void calcfact()
{
    fact[1] = 1;
    rep(i, 2, 300001) fact[i] = (fact[i - 1] * i) % M;
}

ll calc(vector<pair<int, int>> &a, int n)
{
    ll cur = 1;
    rep(i, 0, n)
    {
        int j = i;
        while (j < n - 1 && a[j].first == a[j + 1].first)
            j++;
        cur = (cur * fact[j - i + 1]) % M;
        i = j;
    }
    return cur;
}

bool is_eq(vector<pair<int, int>> &a, int n)
{
    rep(i, 0, n - 1) if (a[i].first != a[i + 1].first) return 0;
    return 1;
}

void solve(int T)
{
    calcfact();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n), c(n);
    rep(i, 0, n)
    {
        cin >> a[i].first >> b[i].first;
        a[i].second = b[i].second = i;
        c[i].first = a[i].first;
        c[i].second = b[i].first;
    }
    if (is_eq(a, n))
    {
        cout << 0;
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll x = fact[n], y = (calc(a, n) + calc(b, n)) % M, z = 1;
    rep(i, 0, n)
    {
        if ((i && c[i].second < c[i - 1].second) || (i < n - 1 && c[i].second > c[i + 1].second))
        {
            z = 0;
            break;
        }
        int j = i;
        while (j < n - 1 && c[j + 1].first == c[j].first && c[j + 1].second == c[j].second)
            j++;
        z = (z * fact[j - i + 1]) % M;
        i = j;
    }
    x = (x + z) % M;
    cout << ((x - y) % M + M) % M;
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