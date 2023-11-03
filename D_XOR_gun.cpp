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
    vi bits(n + 1);
    rep(i, 1, n)
    {
        irep(j, 30, 0)
        {
            if ((1 << j)&a[i])
            {
                bits[i] = j;
                break;
            }
        }
    }
    rep(i, 3, n)
    {
        if (bits[i - 2] == bits[i - 1] && bits[i - 1] == bits[i])
        {
            cout << 1;
            return;
        }
    }
    int ans = 1e9;
    rep(i, 1, n)
    {
        int x = 0, xc = 0;
        rep(j, i, n)
        {
            x ^= a[j];
            xc++;
            int y = 0, yc = 0;
            rep(k, j + 1, n)
            {
                y ^= a[k];
                yc++;
                if (y < x)
                    ans = min(ans, xc - 1 + yc - 1);
            }
        }
    }
    if (ans == 1e9)
        ans = -1;
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
