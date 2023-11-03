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
#define vvvi vector<vector<vector<int>>>
ll M = 1e9 + 7;

void solve()
{
    int n, h;
    cin >> n >> h;
    vpi a(n);
    vi ans(n, 1);
    rep(i, 0, n - 1)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    if (n == 2)
    {
        cout << 0 << "\n" << 1 << " " << 1;
        return;
    }
    sort(a.begin(), a.end());
    int mx = a[n - 1].first + a[n - 2].first - a[0].first - a[1].first;
    int u = max(a[0].first + a[n - 1].first + h, a[n - 1].first + a[n - 2].first);
    int d = min(a[0].first + a[1].first + h, a[1].first + a[2].first);
    if (u - d < mx)
    {
        ans[a[0].second] = 2;
        mx = u - d;
    }
    cout << mx << "\n";
    for (auto x : ans)
        cout << x << " ";
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
