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

ull sq[1500001];

void solve()
{
    set<pl> ans;
    sq[0] = 0;
    rep(i, 1, 1500000) sq[i] = sq[i - 1] + 1ll * i * i;
    ull x;
    cin >> x;
    for (ull i = 1; i <= 1500000 && sq[i - 1] <= x; i++)
    {
        ull y = x - sq[i - 1];
        ull num = (2ll * y) + (i * i * i) - (i * i);
        ull dem = (i * i) + i;
        if (num > 0 && dem > 0 && num % dem == 0)
        {
            ans.insert({i, num / dem});
            ans.insert({num / dem, i});
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x.first << " " << x.second << "\n";
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
