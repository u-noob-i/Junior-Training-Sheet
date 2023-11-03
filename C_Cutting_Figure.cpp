#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

int n, m, ans;
string a[52];
vvi d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool ispos(int i, int j, int q)
{
    if (i + d[q][0] >= 1 && i + d[q][0] <= n && j + d[q][1] >= 1 && j + d[q][1] <= m && a[i + d[q][0]][j + d[q][1]] == '#')
        return 1;
    return 0;
}

void dfs(int i, int j, vector<vector<bool>> &v)
{
    v[i][j] = 1;
    rep(q, 0, 3) if (ispos(i, j, q) && !v[i + d[q][0]][j + d[q][1]]) dfs(i + d[q][0], j + d[q][1], v);
}

bool check()
{
    vector<vector<bool>> v(n + 1, vector<bool>(m + 1, 0));
    int ct = 0;
    rep(i, 1, n) rep(j, 1, m)
    {
        if (!v[i][j] && a[i][j] == '#')
        {
            ct++;
            dfs(i, j, v);
        }
    }
    return (ct <= 1 ? 0 : 1);
}

void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i] = "/" + a[i];
    }
    ans = INF;
    rep(i, 1, n) rep(j, 1, m)
    {
        if (a[i][j] == '.')
            continue;
        rep(k, 0, 15)
        {
            vector<bool> v(4, 0);
            int ct = 0;
            rep(q, 0, 3)
            {
                if (((1 << q) & k) && ispos(i, j, q))
                {
                    a[i + d[q][0]][j + d[q][1]] = '.';
                    v[q] = 1;
                    ct++;
                }
            }
            if (ct < ans && check())
                ans = ct;
            rep(q, 0, 3) if (v[q]) a[i + d[q][0]][j + d[q][1]] = '#';
        }
    }
    cout << (ans == INF ? -1 : ans);
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve();
        cout << "\n";
    }
}