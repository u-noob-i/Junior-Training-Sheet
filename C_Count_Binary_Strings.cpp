#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e18
#define pb push_back()
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
int M = 998244353;

int n;
int a[105][105];
int dp[105][105][105];

bool check(int i, int p0, int p1)
{
    rep(j, 1, i)
    {
        if (a[j][i] == 0)
            continue;
        if (a[j][i] == 1 && p0 >= j && p0 <= i && p1 >= j && p1 <= i)
            return 0;
        else if (a[j][i] == 2 && (p0 < j || p1 < j))
            return 0;
    }
    return 1;
}

int rec(int i, int p0, int p1)
{
    if (i > n)
        return 1;
    if (dp[i][p0][p1] != -1)
        return dp[i][p0][p1];
    int ans = 0;
    if (check(i, p0, i))
        ans = (ans + rec(i + 1, p0, i)) % M;
    if (check(i, i, p1))
        ans = (ans + rec(i + 1, i, p1)) % M;
    dp[i][p0][p1] = ans;
    return ans;
}

void solve()
{
    cin >> n;
    rep(i, 1, n) rep(j, i, n) cin >> a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << rec(1, 0, 0);
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
