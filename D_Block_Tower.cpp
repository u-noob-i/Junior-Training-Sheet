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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

vector<string> a(501);
vector<vector<bool>> vis(501, vector<bool>(501, 0));
vector<pair<char, pair<int, int>>> ans;
int n, m;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (x > 0 && !vis[x - 1][y])
        dfs(x - 1, y);
    if (x < n - 1 && !vis[x + 1][y])
        dfs(x + 1, y);
    if (y > 0 && !vis[x][y - 1])
        dfs(x, y - 1);
    if (y < m - 1 && !vis[x][y + 1])
        dfs(x, y + 1);
    ans.push_back({'D', {x + 1, y + 1}});
    ans.push_back({'R', {x + 1, y + 1}});
    return;
}

void solve(int T)
{
    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) rep(j, 0, m) if (a[i][j] == '#') vis[i][j] = 1;
    rep(i, 0, n) rep(j, 0, m) if (!vis[i][j]) ans.push_back({'B', {i + 1, j + 1}});
    rep(i, 0, n) rep(j, 0, m)
    {
        if (vis[i][j])
            continue;
        dfs(i, j);
        ans.pop_back();
        ans.pop_back();
    }
    cout << ans.size() << "\n";
    rep(i, 0, ans.size()) cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
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
        solve(T);
        cout << "\n";
    }
}