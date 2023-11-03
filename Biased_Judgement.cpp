#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
ll M = 1e9 + 7;

ll GCD(ll x, ll y) { return (y == 0 ? x : GCD(y % x, x)); }

int a[1001][1001];
bool c[1001][1001];
bool w[1001];

void solve()
{
    int n, m;
    cin >> n >> m;
    int ff = 0;
    rep(i, 1, n)
    {
        cin >> w[i];
        if (!w[i])
            ff++;
    }
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) rep(j, 1, m) cin >> c[i][j];
    vi mt(n + 1, 0);
    if (ff == n)
    {
        rep(i, 1, n)
        {
            rep(j, 1, m)
            {
                if (!c[i][j])
                    mt[i] = 1e9;
                mt[i] = max(mt[i], a[i][j]);
            }
        }
        int mn = 1e9;
        rep(i, 1, n) mn = min(mn, mt[i]);
        if (mn > 1)
        {
            cout << "YES\n1 " << m << "\n";
            rep(i, 1, m) cout << i << " ";
        }
        else
            cout << "NO";
        return;
    }
    if (!ff)
    {
        cout << "YES\n1000000000 1\n1";
        return;
    }
    vpi tle;
    rep(i, 1, m)
    {
        bool f = 1;
        int t = 0;
        rep(j, 1, n)
        {
            if (!w[j])
                continue;
            if (!c[j][i])
                f = 0;
            t = max(t, a[j][i]);
        }
        if (f)
            tle.pb({t, i});
    }
    if (!tle.size())
    {
        cout << "NO";
        return;
    }
    sort(tle.begin(), tle.end());
    vb f(n + 1, 0);
    rep(k, 0, tle.size() - 1)
    {
        int j = tle[k].second, t = tle[k].first;
        int mn = 1e9;
        rep(i, 1, n)
        {
            if (w[i])
                continue;
            if (!c[i][j])
                mt[i] = 1e9;
            mt[i] = max(mt[i], a[i][j]);
            mn = min(mn, mt[i]);
        }
        if (mn > t)
        {
            cout << "YES\n" << t << " " << k + 1 << "\n";
            vi ans;
            rep(i, 0, k) ans.pb(tle[i].second);
            sort(ans.begin(), ans.end());
            for (auto x : ans) cout << x << " ";
            return;
        }
    }
    cout << "NO";
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
    cin >> tt;
    for (int ttt = 1; ttt <= tt; ttt++)
    {
        solve();
        cout << "\n";
    }
}
