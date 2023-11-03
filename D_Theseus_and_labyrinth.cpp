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
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

int n, m;
set<int> sccadj[200005];
vector<bool> vis;
string a[10001];

void rot(char &x)
{
    switch (x)
    {
    case '-':
        x = '|';
        break;
    case '|':
        x = '-';
        break;
    case '^':
        x = '>';
        break;
    case '>':
        x = 'v';
        break;
    case 'v':
        x = '<';
        break;
    case '<':
        x = '^';
        break;
    case 'L':
        x = 'U';
        break;
    case 'U':
        x = 'R';
        break;
    case 'R':
        x = 'D';
        break;
    case 'D':
        x = 'L';
        break;
    default:
        break;
    }
    return;
}

bool hasedge(int x1, int y1, int x2, int y2, char p, char q)
{
    if (x2 + 1 == x1 && (q == '+' || q == '|' || q == 'L' || q == 'R' || q == 'U' || q == 'v') &&
        (p == '+' || p == '|' || p == 'L' || p == 'R' || p == 'D' || p == '^'))
        return 1;
    else if (x1 + 1 == x2 && (p == '+' || p == '|' || p == 'L' || p == 'R' || p == 'U' || p == 'v') &&
             (q == '+' || q == '|' || q == 'L' || q == 'R' || q == 'D' || q == '^'))
        return 1;
    else if (y2 + 1 == y1 && (q == '+' || q == '-' || q == '>' || q == 'L' || q == 'D' || q == 'U') &&
             (p == '+' || p == '-' || p == '<' || p == 'R' || p == 'D' || p == 'U'))
        return 1;
    else if (y1 + 1 == y2 && (p == '+' || p == '-' || p == '>' || p == 'L' || p == 'D' || p == 'U') &&
             (q == '+' || q == '-' || q == '<' || q == 'R' || q == 'D' || q == 'U'))
        return 1;
    return 0;
}

void solve()
{
    vvi d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i] = "/" + a[i];
    }
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    vvvi dp(n + 1, vvi(m + 1, vi(4, INF)));
    queue<vi> q;
    dp[sx][sy][0] = 0;
    q.push({sx, sy, 0, 0});
    while (q.size())
    {
        vi t = q.front();
        q.pop();
        if (dp[t[0]][t[1]][t[2]] != t[3])
            continue;
        if (dp[t[0]][t[1]][(t[2] + 1) % 4] > t[3] + 1)
        {
            dp[t[0]][t[1]][(t[2] + 1) % 4] = t[3] + 1;
            q.push({t[0], t[1], (t[2] + 1) % 4, t[3] + 1});
        }
        rep(i, 0, 3)
        {
            int x = t[0] + d[i][0], y = t[1] + d[i][1];
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            char p = a[t[0]][t[1]], r = a[x][y];
            rep(j, 1, t[2])
            {
                rot(p);
                rot(r);
            }
            if (dp[x][y][t[2]] > t[3] + 1 && hasedge(t[0], t[1], x, y, p, r))
            {
                dp[x][y][t[2]] = t[3] + 1;
                q.push({x, y, t[2], t[3] + 1});
            }
        }
    }
    int ans = INF;
    rep(i, 0, 3) ans = min(ans, dp[dx][dy][i]);
    if (ans == INF)
        ans = -1;
    cout << ans;
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
