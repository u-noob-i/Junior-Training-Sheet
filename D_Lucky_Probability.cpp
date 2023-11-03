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

vl lucki;

void genluck()
{
    lucki.pb(0);
    int j = 0;
    rep(i, 1, 9)
    {
        int n = lucki.size();
        while (j < n)
        {
            lucki.pb(lucki[j] * 10 + 4);
            lucki.pb(lucki[j] * 10 + 7);
            j++;
        }
    }
    lucki.pb(1e9 + 1);
    sort(lucki.begin(), lucki.end());
}

void solve()
{
    genluck();
    ll ax, ay, bx, by, k, m = lucki.size() - 1;
    cin >> ax >> ay >> bx >> by >> k;
    double ans = 0, dem = 1.0 * (ay - ax + 1) * (by - bx + 1);
    rep(i, 1, m - k + 1)
    {
        double temp = 0;
        if (lucki[i] >= ax && lucki[i + k - 1] <= by)
        {
            temp += 1.0 * max(0ll, (min(ay, lucki[i]) - max(ax, lucki[i - 1] + 1) + 1)) *
                    max(0ll, (min(by, lucki[i + k] - 1) - max(bx, lucki[i + k - 1]) + 1));
        }
        if (lucki[i] >= bx && lucki[i + k - 1] <= ay)
        {
            temp += 1.0 * max(0ll, (min(by, lucki[i]) - max(bx, lucki[i - 1] + 1) + 1)) *
                    max(0ll, (min(ay, lucki[i + k] - 1) - max(ax, lucki[i + k - 1]) + 1));
        }
        if (k == 1 && lucki[i] >= ax && lucki[i] <= ay && lucki[i] >= bx && lucki[i] <= by)
            temp--;
        ans += temp / dem;
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
