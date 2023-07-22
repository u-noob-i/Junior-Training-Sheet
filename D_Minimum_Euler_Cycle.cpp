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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
ll M = 1000000007;

int spf[100001];

void sieve()
{
    rep(i, 1, 100001) spf[i] = i;
    for (i = 2; i < 100001; i += 2)
        spf[i] = 2;
    for (i = 3; i < 100001; i += 2)
        if (spf[i] == i)
            for (j = i + i; j < 100001; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    return;
}

map<ll, ll> factr(ll x)
{
    map<ll, ll> ret;
    while (x > 1)
    {
        ret[spf[x]]++;
        x /= spf[x];
    }
    return ret;
}

ll pow(ll x, ll y)
{
    ll ret = 1;
    while (y--)
        ret *= x;
    return ret;
}

void solve(int T)
{
    ll l, r;
    cin >> n >> l >> r;
    ll cur = 1, u, v;
    rep(i, 1, n + 1)
    {
        if (cur + 2ll * (n - i) < l)
            cur += 2ll * (n - i);
        else if (cur + 2ll * (n - i) == l)
        {
            u = i + 1;
            v = u + 1;
            break;
        }
        else
        {
            u = i;
            v = u + 1;
            v += (l - cur) / 2;
            break;
        }
    }
    while (l <= r)
    {
        if (l % 2)
        {
            if (u == n)
                u = 1;
            cout << u << " ";
        }
        else
        {
            cout << v++ << " ";
            if (v > n)
            {
                u++;
                v = u + 1;
            }
        }
        l++;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}