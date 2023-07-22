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
    sieve();
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll tp = 0;
    map<ll, ll> arr, b;
    rep(i, 0, n)
    {
        map<ll, ll> f = factr(a[i]);
        a[i] = 1;
        bool ispf = 1;
        ll temp = 1;
        for (auto itr : f)
        {
            int x = itr.second % k;
            if (x)
            {
                ispf = 0;
                a[i] *= pow(itr.first, x);
                temp *= pow(itr.first, k - x);
            }
        }
        if (ispf)
            tp++;
        else
        {
            // cout << i << " " << a[i] << " " << temp << "\n";
            arr[a[i]]++;
            b[a[i]] = temp;
        }
    }
    ll ans = 0;
    for (auto itr : arr)
    {
        if (!itr.second)
            continue;
        if (b[itr.first] == itr.first)
            ans += itr.second * (itr.second - 1) / 2;
        else
        {
            ans += 1ll * itr.second * arr[b[itr.first]];
            itr.second = 0;
            arr[b[itr.first]] = 0;
        }
    }
    ans += tp * (tp - 1) / 2;
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