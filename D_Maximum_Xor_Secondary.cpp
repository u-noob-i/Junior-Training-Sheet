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

int a[100001];

void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    stack<int> s;
    vi ng(n + 1), pg(n + 1);
    rep(i, 1, n)
    {
        while (s.size() && a[s.top()] < a[i])
        {
            ng[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while (s.size())
    {
        ng[s.top()] = -1;
        s.pop();
    }
    irep(i, n, 1)
    {
        while (s.size() && a[s.top()] < a[i])
        {
            pg[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while (s.size())
    {
        pg[s.top()] = -1;
        s.pop();
    }
    int ans = -1;
    rep(i, 1, n)
    {
        if (ng[i] != -1)
            ans = max(ans, a[i] ^ ng[i]);
        if (pg[i] != -1)
            ans = max(ans, a[i] ^ pg[i]);
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
