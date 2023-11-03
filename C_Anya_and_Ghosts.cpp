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

void solve()
{
    int n, t, r;
    cin >> n >> t >> r;
    vi a(n), b(n, 0);
    set<int> candles;
    rep(i, 0, n - 1) cin >> a[i];
    int ans = 0;
    rep(i, 0, n - 1)
    {
        int j = a[i] - 1;
        while (j + t >= a[i] && b[i] < r)
        {
            if (candles.find(j) != candles.end())
            {
                j--;
                continue;
            }
            ans++;
            b[i]++;
            candles.insert(j);
            rep(k, i + 1, n - 1)
            {
                if (a[k] <= j + t)
                    b[k]++;
                else
                    break;
            }
            j--;
        }
        if (b[i] < r)
        {
            ans = -1;
            break;
        }
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
