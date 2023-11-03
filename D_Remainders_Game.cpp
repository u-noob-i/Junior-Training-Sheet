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
ll M = 1e9 + 7;

int spf[1000001];

void sieve()
{
    rep(i, 1, 1000000) spf[i] = i;
    for (int i = 4; i <= 1000000; i += 2)
        spf[i] = 2;
    for (int i = 3; i <= 1000000; i += 2)
        if (spf[i] == i)
            for (int j = i + i; j <= 1000000; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

ll gcd(ll x, ll y)
{
    if (!y)
        return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

void solve()
{
    sieve();
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    map<int, int> ct;
    while (k != 1)
    {
        int x = spf[k];
        while (k % x == 0)
        {
            k /= x;
            ct[x]++;
        }
    }
    rep(i, 0, n - 1)
    {
        while (a[i] != 1)
        {
            int x = spf[a[i]];
            int c = 0;
            while (a[i] % x == 0)
            {
                a[i] /= x;
                c++;
            }
            if (ct.find(x) == ct.end())
                continue;
            if (ct[x] <= c)
                ct.erase(x);
        }
    }
    if (!ct.size())
        cout << "Yes";
    else
        cout << "No";
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
