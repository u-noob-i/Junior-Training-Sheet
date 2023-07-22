#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    vector<vector<pair<int, int>>> ans(n);
    for (i = 0; i < n; i++)
        ans[i].push_back({i + 1, i + 1});
    for (i = 0, j = n + 1; i < m; i++)
    {
        ans[a[i].first - 1].push_back({a[i].first, j});
        ans[a[i].second - 1].push_back({a[i].second, j});
        j++;
    }
    for (i = 0; i < n; i++)
    {
        cout << ans[i].size() << "\n";
        for (j = 0; j < ans[i].size(); j++)
            cout << ans[i][j].first << " " << ans[i][j].second << "\n";
    }
}

int main()
{
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}