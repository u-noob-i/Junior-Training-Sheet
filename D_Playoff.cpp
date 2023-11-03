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
ll M = 1e9 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
    int less = 0, more = 0;
    rep(j, 1, n)
    {
        if (s[j] == '1')
            less += less + 1;
        else
            more += more + 1;
    }
    rep(i, less + 1, (1 << n) - more) cout << i << " ";
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
