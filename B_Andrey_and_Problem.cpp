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

int n;
vector<double> a;

void solve()
{
    cin >> n;
    a.resize(n + 1, 0);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    double ans = 0;
    irep(i, n, 1)
    {
        double cc = 0;
        rep(j, i, n)
        {
            double cf = a[j];
            rep(k, i, n)
            {
                if (j == k)
                    continue;
                cf *= 1 - a[k];
            }
            cc += cf;
        }
        ans = max(ans, cc);
    }
    cout << fixed << setprecision(11) << ans;
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
