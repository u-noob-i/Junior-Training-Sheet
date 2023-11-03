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

vi a;
vvvi dp;
vector<vector<bool>> adj;

int gcd(int x, int y)
{
    if (!y)
        return x;
    return gcd(y, x % y);
}

int rec(int l, int r, int side)
{
    if (l == r)
    {
        if (!side && adj[r][r + 1])
            return 1;
        if (side && adj[l - 1][l])
            return 1;
        return 0;
    }
    if (dp[l][r][side] != -1)
        return dp[l][r][side];
    int root = (side ? l - 1 : r + 1);
    dp[l][r][side] = 0;
    rep(i, l, r)
    {
        if (!adj[root][i])
            continue;
        if (i == l)
        {
            if (rec(i + 1, r, 1))
            {
                dp[l][r][side] = 1;
                break;
            }
        }
        else if (i == r)
        {
            if (rec(l, i - 1, 0))
            {
                dp[l][r][side] = 1;
                break;
            }
        }
        else if (rec(l, i - 1, 0) && rec(i + 1, r, 1))
        {
            dp[l][r][side] = 1;
            break;
        }
    }
    return dp[l][r][side];
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    dp.assign(n + 1, vvi(n + 1, vi(2, -1)));
    adj.assign(n + 1, vector<bool>(n + 1, 0));
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, i + 1, n) if (gcd(a[i], a[j]) > 1) adj[i][j] = adj[j][i] = 1;
    rep(i, 1, n)
    {
        if (i == 1)
        {
            if (rec(2, n, 1))
            {
                cout << "Yes";
                return;
            }
        }
        else if (i == n)
        {
            if (rec(1, n - 1, 0))
            {
                cout << "Yes";
                return;
            }
        }
        else if (rec(1, i - 1, 0) && rec(i + 1, n, 1))
        {
            cout << "Yes";
            return;
        }
    }
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
