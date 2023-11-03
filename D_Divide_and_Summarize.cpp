#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e9
#define pb push_back()
#define pr pop_back()
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
ll M = 1e9 + 7;

vi a;
vl pref;
set<ll> sums;

int getind(int l, int r, int x)
{
    int mid, ret = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] <= x)
        {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ret;
}

void bs(int l, int r)
{
    if (l > r)
        return;
    sums.insert(pref[r] - pref[l - 1]);
    if (l == r)
        return;
    int m = getind(l, r, (a[l] + a[r]) / 2);
    if (m == r)
        return;
    bs(l, m);
    bs(m + 1, r);
    return;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n + 1, 0);
    pref.resize(n + 1, 0);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, 1, n) pref[i] = pref[i - 1] + a[i];
    sums.clear();
    bs(1, n);
    while (q--)
    {
        ll x;
        cin >> x;
        if (sums.find(x) == sums.end())
            cout << "No\n";
        else
            cout << "Yes\n";
    }
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

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve();
        // cout << "\n";
    }
}
