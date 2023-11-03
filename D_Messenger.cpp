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

void inn(vector<pair<ll, char>> &a, int n)
{
    rep(i, 0, n - 1)
    {
        string s;
        cin >> s;
        ll x;
        char ch;
        x = stoi(s.substr(0, s.length() - 2));
        ch = s[s.length() - 1];
        if (a.size() && a[a.size() - 1].second == ch)
            a[a.size() - 1].first += x;
        else
            a.pb({x, ch});
    }
}

vector<int> zfun(vector<pair<ll, char>> &a, vector<pair<ll, char>> &b)
{
    int n = a.size(), m = b.size();
    vector<pair<ll, char>> t;
    rep(i, 1, m - 2) t.pb({b[i].first, b[i].second});
    t.pb({ -1, '#'});
    t.pb({0, '#'});
    t.pb({ -1, '#'});
    for (auto x : a)
        t.pb(x);
    vector<int> z(n + m);
    z[0] = 0;
    int l = 0, r = 0;
    rep(i, 1, n + m - 1)
    {
        z[i] = 0;
        if (i <= r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n + m && t[i + z[i]].first == t[z[i]].first
                && t[i + z[i]].second == t[z[i]].second)
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

ll lesto(vector<pair<ll, char>> &t, vector<pair<ll, char>> &s)
{
    int n = t.size(), m = s.size();
    ll ret = 0;
    rep(i, 0, n - m)
    {
        if (i + m > n)
            break;
        if (m == 1 && t[i].second == s[0].second)
            ret += max(0ll, t[i].first - s[0].first + 1);
        else if (m == 2 && t[i].second == s[0].second && t[i + 1].second == s[1].second
                 && t[i].first >= s[0].first && t[i + 1].first >= s[1].first)
            ret++;
    }
    return ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, char>> t, s;
    inn(t, n);
    inn(s, m);
    n = t.size();
    m = s.size();
    if (m <= 2)
    {
        cout << lesto(t, s);
        return;
    }
    vector<int> z = zfun(t, s);
    ll ans = 0;
    rep(i, m + 2, n + m - 1)
    {
        // cout << z[i] << " ";
        if (z[i] == m - 2 && t[i - m - 2].first >= s[0].first &&
                t[i - m - 2 + m - 1].first >= s[m - 1].first &&
                t[i - m - 2].second == s[0].second &&
                t[i - m - 2 + m - 1].second == s[m - 1].second)
            ans++;
    }
    cout << ans;
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
