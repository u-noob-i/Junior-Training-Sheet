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
#define vvpi vector<vector<pair<int,int>>>

ll M = 1e9 + 7;

int GCD(int x, int y) { return y == 0 ? x : GCD(y, x % y); }

int n, m = 25;
vi a, lg;
vvi dp;

void callg()
{
    lg.resize(n + 1);
    lg[1] = 0;
    rep(i, 2, n) lg[i] = lg[i / 2] + 1;
}

void gen()
{
    dp.resize(n + 1, vi(m + 1));
    rep(i, 1, n) dp[i][0] = a[i];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = GCD(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int j = lg[r - l + 1];
    return GCD(dp[l][j], dp[r - (1 << j) + 1][j]);
}

int bs(int L, int R, int x, bool side)
{
    int l = L, r = R, ret = -1, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (side)
        {
            if (query(mid, R) == x)
            {
                ret = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        else
        {
            if (query(L, mid) == x)
            {
                ret = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    return ret;
}

void solve()
{
    cin >> n;
    a.resize(n + 1);
    rep(i, 1, n) cin >> a[i];
    callg();
    gen();
    int mv = -1;
    set<int> vs;
    rep(i, 1, n)
    {
        int l = bs(1, i, a[i], 1), r = bs(i, n, a[i], 0);
        // cout << a[i] << " " << l << " " << r << "\n";
        if (r - l > mv)
        {
            mv = r - l;
            vs.clear();
        }
        if (r - l == mv)
            vs.insert(l);
    }
    cout << vs.size() << " " << mv << "\n";
    for (auto i : vs)
        cout << i << " ";
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
    for (int ttt = 1; ttt <= tt; ttt++)
    {
        solve();
        cout << "\n";
    }
}
