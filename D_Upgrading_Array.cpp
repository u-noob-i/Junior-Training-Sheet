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

int n, m;

int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}

vpi primefact(int x)
{
    vpi ret;
    int ct;
    if (x % 2 == 0)
    {
        ct = 0;
        while (x % 2 == 0)
            x /= 2, ct++;
        ret.push_back({2, ct});
    }
    for (int i = 3; i <= sqrt(x); i += 2)
    {
        if (x % i == 0)
        {
            ct = 0;
            while (x % i == 0)
                x /= i, ct++;
            ret.push_back({i, ct});
        }
    }
    if (x > 1)
        ret.push_back({x, 1});
    return ret;
}

void solve()
{
    cin >> n >> m;
    vi a(n + 2);
    set<int> b;
    rep(i, 1, n) cin >> a[i];
    a[n + 1] = a[n];
    rep(i, 1, m)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    vi g(n + 1, 1);
    vector<vpi> pf(n + 1);
    rep(i, 1, n)
    {
        if (i == 1)
            g[i] = a[1];
        else
            g[i] = gcd(g[i - 1], a[i]);
        pf[i] = primefact(a[i]);
    }
    int ans = 0;
    rep(i, 1, n)
    {
        for (auto itr : pf[i])
        {
            if (b.find(itr.first) == b.end())
                ans += itr.second;
            else
                ans -= itr.second;
        }
    }
    int div = 1;
    vpi gf;
    irep(i, n, 1)
    {
        g[i] /= div;
        gf = primefact(g[i]);
        int t = 0;
        for (auto itr : gf)
        {
            if (b.find(itr.first) == b.end())
                t -= itr.second;
            else
                t += itr.second;
        }
        if (t > 0)
        {
            // cout << i << " " << g[i] << "\n";
            div *= g[i];
            ans += t * i;
        }
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
