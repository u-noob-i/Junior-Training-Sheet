#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF 1e9
#define pb push_back
#define pr pop_back
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
ll M = 998244353;

ll gcd(ll x, ll y)
{
    if (!y)
        return x;
    return gcd(y , x % y);
}

void solve()
{
    int n;
    cin >> n;
    vpl a;
    ll x, y;
    map<ll, ll> ct;
    rep(i, 0, n - 1)
    {
        cin >> x;
        y = sqrtl(x);
        y = sqrtl(y);
        if (y * y * y * y == x)
        {
            ct[y] += 4;
            a.pb({x, 1});
            continue;
        }
        y = sqrtl(x);
        if (y * y == x)
        {
            ct[y] += 2;
            a.pb({x, 1});
            continue;
        }
        y = cbrt(x);
        if (y * y * y == x)
        {
            ct[y] += 3;
            a.pb({x, 1});
            continue;
        }
        a.pb({x, 0});
    }
    rep(i, 0, n - 1)
    {
        if (a[i].second)
            continue;
        rep(j, 0, n - 1)
        {
            if (i == j || a[i].first == a[j].first)
                continue;
            x = gcd(a[i].first, a[j].first);
            if (x == 1)
                continue;
            ct[x]++;
            ct[a[i].first / x]++;
            a[i].second = 1;
            break;
        }
    }
    map<ll, ll> nn;
    for (auto i : a)
        if (!i.second)
            nn[i.first]++;
    ll ans = 1;
    for (auto i : ct)
        ans = (ans * (i.second + 1)) % M;
    for (auto i : nn)
        ans = (ans * (i.second + 1) * (i.second + 1)) % M;
    cout << ans << "\n";
    cout.flush();
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
