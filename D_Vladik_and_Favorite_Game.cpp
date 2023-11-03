#include <iostream>
#include <cstring>
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
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i] = "0" + a[i];
    }
    vvi p(n + 1, vi(m + 1, INF));
    queue<pi> q;
    rep(i, 1, n) rep(j, 1, m) if (a[i][j] == 'F') q.push({i, j});
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x > 1 && p[x - 1][y] == INF && a[x - 1][y] != '*')
        {
            p[x - 1][y] = 1;
            q.push({x - 1, y});
        }
        if (x < n && p[x + 1][y] == INF && a[x + 1][y] != '*')
        {
            p[x + 1][y] = 0;
            q.push({x + 1, y});
        }
        if (y > 1 && p[x][y - 1] == INF && a[x][y - 1] != '*')
        {
            p[x][y - 1] = 3;
            q.push({x, y - 1});
        }
        if (y < m && p[x][y + 1] == INF && a[x][y + 1] != '*')
        {
            p[x][y + 1] = 2;
            q.push({x, y + 1});
        }
    }
    bool l = 0, u = 0;
    int x = 1, y = 1;
    int r, c;
    char ch[] = {'U', 'D', 'L', 'R'};
    while (a[x][y] != 'F')
    {
        if (!u && p[x][y] == 1)
        {
            u = 1;
            cout << ch[1] << "\n";
            cout.flush();
            cin >> r >> c;
            if (r == x && y == c)
            {
                swap(ch[0], ch[1]);
                cout << ch[1] << "\n";
                cout.flush();
                cin >> r >> c;
            }
            x = r;
            y = c;
            continue;
        }
        if (!l && p[x][y] == 3)
        {
            l = 1;
            cout << ch[3] << "\n";
            cout.flush();
            cin >> r >> c;
            if (r == x && y == c)
            {
                swap(ch[2], ch[3]);
                cout << ch[3] << "\n";
                cout.flush();
                cin >> r >> c;
            }
            x = r;
            y = c;
            continue;
        }
        cout << ch[p[x][y]] << "\n";
        cout.flush();
        cin >> x >> y;
    }
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
