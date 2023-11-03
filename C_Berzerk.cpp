#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e18
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


void solve()
{
    vvi a(2), c(2), v(2);
    int n, m, k;
    cin >> n >> m;
    a[0].resize(m + 1);
    rep(i, 1, m) cin >> a[0][i];
    cin >> k;
    a[1].resize(k + 1);
    rep(i, 1, k) cin >> a[1][i];

    v[0].assign(n + 1, -1);
    v[1].assign(n + 1, -1);
    c[0].assign(n + 1, m);
    c[1].assign(n + 1, k);

    v[0][1] = v[1][1] = 2;
    queue<pi> q;
    q.push({0, 1});
    q.push({1, 1});
    while (q.size())
    {
        int t = q.front().first, i = q.front().second, x;
        q.pop();
        rep(j, 1, a[!t].size() - 1)
        {
            x = i - a[!t][j];
            if (x <= 0)
                x += n;
            if (v[!t][x] != -1)
                continue;
            if (v[t][i] == 1)
            {
                c[!t][x]--;
                if (!c[!t][x])
                {
                    v[!t][x] = 2;
                    q.push({!t, x});
                }
            }
            else
            {
                v[!t][x] = 1;
                q.push({!t, x});
            }
        }
    }
    rep(i, 2, n)
    {
        if (v[0][i] == 1)
            cout << "Win ";
        else if (v[0][i] == 2)
            cout << "Lose ";
        else
            cout << "Loop ";
    }
    cout << "\n";
    rep(i, 2, n)
    {
        if (v[1][i] == 1)
            cout << "Win ";
        else if (v[1][i] == 2)
            cout << "Lose ";
        else
            cout << "Loop ";
    }
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
