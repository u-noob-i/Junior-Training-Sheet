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

void solve()
{
    int n, a, b, t;
    string s;
    cin >> n >> a >> b >> t >> s;
    vi pref(n, a + 1), suf(n, a + 1);
    pref[0] -= a;
    if (s[0] == 'w')
        pref[0] += b;
    rep(i, 1, n - 1)
    {
        pref[i] += pref[i - 1];
        if (s[i] == 'w')
            pref[i] += b;
    }
    if (s[n - 1] == 'w')
        suf[n - 1] += b;
    irep(i, n - 2, 0)
    {
        suf[i] += suf[i + 1];
        if (s[i] == 'w')
            suf[i] += b;
    }
    int ans = 0;
    rep(i, 0, n - 1)
    {
        if (pref[i] > t)
            break;
        int x = pref[i];
        int l = i + 1, r = n - 1, mid, val = n;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            int cost = pref[i] + suf[mid] + a * min(i, n - mid);
            if (cost <= t)
            {
                val = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        ans = max(ans, i + 1 + n - val);
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

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve();
        cout << "\n";
    }
}
