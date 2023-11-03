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

char a[501][501];
bool v[501][501];
int n, m;

bool ispos(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || v[x][y] || a[x][y] == 'X')
        return 0;
    return 1;
}

bool isg(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 'X')
        return 0;
    return 1;
}

void dfs(int x, int y)
{
    v[x][y] = 1;
    if (ispos(x + 1, y))
        dfs(x + 1, y);
    if (ispos(x - 1, y))
        dfs(x - 1, y);
    if (ispos(x, y + 1))
        dfs(x, y + 1);
    if (ispos(x, y - 1))
        dfs(x, y - 1);
    return;
}

void solve()
{
    int x1, x2, y1, y2;
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m)
    {
        cin >> a[i][j];
        v[i][j] = 0;
    }
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
    {
        if (isg(x1 - 1, y1) || isg(x1 + 1, y1) || isg(x1, y1 - 1) || isg(x1, y1 + 1))
            cout << "YES";
        else
            cout << "NO";
        return;
    }
    int ct = 0;
    if (isg(x2 - 1, y2))
        ct++;
    if (isg(x2 + 1, y2))
        ct++;
    if (isg(x2, y2 - 1))
        ct++;
    if (isg(x2, y2 + 1))
        ct++;
    if (ct < 2 && a[x2][y2] == '.')
    {
        if (ct == 1 && ((x1 == x2 && (y1 == y2 + 1 || y1 == y2 - 1)) || (y1 == y2 && (x1 == x2 + 1 || x1 == x2 - 1))))
            cout << "YES";
        else
            cout << "NO";
        return;
    }
    a[x2][y2] = '.';
    dfs(x1, y1);
    if (v[x2][y2])
        cout << "YES";
    else
        cout << "NO";
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