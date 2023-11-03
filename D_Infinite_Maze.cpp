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

int dir[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
int n, m;
vector<string> a;
vector<vb> vis;
vector<vpi> v;

bool dfs(int x, int y)
{
    int X = (x % n + n) % n, Y = (y % m + m) % m;
    if (a[X][Y] == '#')
        return 0;
    if (vis[X][Y])
        return (v[X][Y].first != x || v[X][Y].second != y);
    vis[X][Y] = 1;
    v[X][Y] = {x, y};
    bool ret = 0;
    rep(i, 0, 3)
    {
        ret |= dfs(x + dir[i][0], y + dir[i][1]);
    }
    return ret;
}

void solve()
{
    int sx, sy;
    cin >> n >> m;
    a.resize(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        rep(j, 0, m - 1)
        {
            if (a[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    v.resize(n, vpi(m));
    vis.assign(n, vb(m, 0));
    if (dfs(sx, sy))
        cout << "Yes";
    else
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
